#include <node.h>
#include <letternode.h>
#include <resultnode.h>
#include <QtDebug>
#include <model.h>

Node::Node(Node *parent)
    : QObject(), m_result_children(),
#if defined(EXTENSIVE_TREE)
      m_letter_children(LETTER_CHILDREN_COUNT),
#else
      m_letter_children(),
#endif
      m_parent(parent) {
}

Node::Node(const Node &node)
    : m_result_children(node.m_result_children),
      m_letter_children(node.m_letter_children), m_parent(node.m_parent) {}

Node::~Node() {
    m_result_children.clear();
    m_letter_children.clear();
}

Node &Node::operator=(const Node &node) {
    m_parent = node.m_parent;
    m_result_children.clear();
    m_result_children = node.m_result_children;
    m_letter_children.clear();
    m_letter_children = node.m_letter_children;
    return *this;
}

Node *Node::parent() const { return m_parent; }

void Node::setParent(Node *parent) { m_parent = parent; }

QString Node::toString(bool /* isAffix */) const { return QString::null; }

QVector<QSharedPointer<LetterNode>> Node::letterChildren() {
#if defined(BINARY_SEARCH)
    return m_letter_children;
#elif defined(HASH_TABLE)
    return m_letter_children.values().toVector();
#elif defined(EXTENSIVE_TREE)
    return m_letter_children;
#endif
}

QSharedPointer<LetterNode> Node::letterChild(const QChar &letter) {
#if defined(BINARY_SEARCH)
    QSharedPointer<LetterNode> searchNode(new LetterNode(letter));
    const std::vector<QSharedPointer<LetterNode>> &letter_vector =
        m_letter_children.toStdVector();
    auto it =
        binary_find(letter_vector.begin(), letter_vector.end(), searchNode);
    if (it != letter_vector.end()) {
        return *it;
    } else {
        return QSharedPointer<LetterNode>(nullptr);
    }
#elif defined(HASH_TABLE)
    return m_letter_children.value(letter, QSharedPointer<LetterNode>(nullptr));
#elif defined(EXTENSIVE_TREE)
    int i = letterIndex(letter);
    qDebug() << "SIZE: " << m_letter_children.size() << " INDEX: " << i;
    return i >= 0 ? m_letter_children.at(i)
                  : QSharedPointer<LetterNode>(nullptr);
#endif
}

// Only LetterNode or ResultNode can be adedd as a child. Others are ignored.
void Node::addChild(Node *child) {
    LetterNode *letterNode = dynamic_cast<LetterNode *>(child);
    if (letterNode != nullptr) {
#if defined(BINARY_SEARCH)
        auto it = std::lower_bound(m_letter_children.begin(),
                                   m_letter_children.end(), child);
        if (it == m_letter_children.end() || *it != child) {
            QSharedPointer<LetterNode> childNode =
                QSharedPointer<LetterNode>(dynamic_cast<LetterNode *>(child));
            m_letter_children.insert(it, childNode);
            letterNode->setParent(this);
            std::sort(m_letter_children.begin(), m_letter_children.end());
        }
#elif defined(HASH_TABLE)
        if (m_letter_children.contains(letterNode->letter())) {
            QSharedPointer<LetterNode> temp =
                m_letter_children[letterNode->letter()];
            if (temp.data() != letterNode) {
                letterNode->setParent(this);
                temp.reset(letterNode);
            }
        } else {
            letterNode->setParent(this);
            m_letter_children.insert(letterNode->letter(),
                                     QSharedPointer<LetterNode>(letterNode));
        }
#elif defined(EXTENSIVE_TREE)
        int index  = letterIndex(letterNode->letter());
        auto & item = m_letter_children[index];
        if (item.data() != letterNode) {
            letterNode->setParent(this);
            item.reset(letterNode);
        }
#endif
    } else if (dynamic_cast<ResultNode *>(child) != nullptr) {
        child->setParent(this);
        m_result_children.append(
            QSharedPointer<ResultNode>(dynamic_cast<ResultNode *>(child)));
    }
}

void Node::addChild(QSharedPointer<Node> child) {
    QSharedPointer<LetterNode> letterNode = child.dynamicCast<LetterNode>();
    if (!letterNode.isNull()) {
        letterNode->setParent(this);
#if defined(BINARY_SEARCH)
        auto it = qLowerBound(m_letter_children.begin(),
                              m_letter_children.end(), letterNode);
        if (it == m_letter_children.end() || *it != child) {
            m_letter_children.insert(it, letterNode);
        }
#elif defined(HASH_TABLE)
        m_letter_children.insert(letterNode->letter(), letterNode);
#elif defined(EXTENSIVE_TREE)
        child->setParent(this);
        m_letter_children[letterIndex(letterNode->letter())] = letterNode;
#endif
    } else {
        QSharedPointer<ResultNode> resultNode = child.dynamicCast<ResultNode>();
        if (!resultNode.isNull()) {
            resultNode->setParent(this);
            m_result_children.append(resultNode);
        }
    }
}

void Node::removeChildren() {
    m_result_children.clear();
#if defined(BINARY_SEARCH)
    m_letter_children.clear();
#elif defined(HASH_TABLE)
    m_letter_children.clear();
#elif defined(EXTENSIVE_TREE)
    m_letter_children.clear();
#endif
}

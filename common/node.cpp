#include <node.h>
#include <letternode.h>
#include <resultnode.h>

Node::Node(Node *parent)
    : QObject(dynamic_cast<QObject *>(parent)), m_result_children(),
      m_letter_children() {}

Node::Node(const Node &node)
    : QObject(dynamic_cast<QObject *>(node.parent())),
      m_result_children(node.m_result_children) {}

Node::~Node() { m_result_children.clear(); }

Node &Node::operator=(const Node &node) {
    setParent(dynamic_cast<QObject *>(node.parent()));
    m_result_children.clear();
    m_result_children = node.m_result_children;
    return *this;
}

Node *Node::parent() const { return dynamic_cast<Node *>(QObject::parent()); }

QVector<QSharedPointer<LetterNode>> &Node::letterChildren() {
#if defined(BINARY_SEARCH)
    return m_letter_children;
#elif defined(HASH_TABLE)
    QHash<QChar, QSharedPointer<LetterNode>> m_letter_children
#elif defined(EXTENSIVE_TREE)
    QVector<QSharedPointer<LetterNode>> m_letter_children
#endif
}

QSharedPointer<LetterNode> Node::letterChild(const QChar &letter) {
#if defined(BINARY_SEARCH)
    auto it = qBinaryFind(m_letter_children.begin(), m_letter_children.end(),
                          QSharedPointer<LetterNode>::create(letter));
    if (it != m_letter_children.end()) {
        return *it;
    } else {
        return QSharedPointer<LetterNode>();
    }
#elif defined(HASH_TABLE)
// TODO:
#elif defined(EXTENSIVE_TREE)
// TODO:
#endif
}

void Node::addChild(Node *child) {
    if (dynamic_cast<LetterNode *>(child) != nullptr) {
        child->setParent(this);
#if defined(BINARY_SEARCH)
        QSharedPointer<LetterNode> childNode =
            QSharedPointer<LetterNode>(dynamic_cast<LetterNode *>(child));
        auto it = qLowerBound(m_letter_children.begin(),
                              m_letter_children.end(), childNode);
        if (it == m_letter_children.end() || *it != childNode) {
            m_letter_children.insert(it, childNode);
        }
#elif defined(HASH_MAP)
#elif defined(EXTENSIVE_TREE)
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
// TODO:
#elif defined(EXTENSIVE_TREE)
// TODO:
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
#elif defined(HASH_MAP)
#elif defined(EXTENSIVE_TREE)
#endif
}

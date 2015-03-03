#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QSharedPointer>

class LetterNode;
class ResultNode;

/*!
 * \brief The Node class is an abstract base class for all nodes.
 */
class Node : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief Node the constructor.
     * \param parent a parent node.
     */
    explicit Node(Node *parent = nullptr);

    /*!
     * \brief Node the copy constructor.
     * \param node the node to copy from.
     */
    explicit Node(const Node &node);

    /*!
     * \brief ~Node the destructor.
     */
    virtual ~Node();

    /*!
     * \brief operator = overloaded assignment operator.
     * \param node the node to assign from.
     * \return updated instance.
     */
    Node &operator=(const Node &node);

    /*!
     * \brief parent returns this nodes parent. This method is more consistent
     * with former \code getPrevious method.
     * \return parent node.
     */
    Node *parent() const;

    /*!
     * \brief isLetterNode return \code true if this is a letter node.
     * \return \code true if this is a letter node.
     */
    virtual bool isLetterNode() const = 0;

    /*!
     * \brief toString returns string representation of a node.
     * \param isAffix treat node as affix one.
     * \return string representation of a node.
     */
    virtual QString toString(bool isAffix = false) const = 0;

    /*!
     * \brief hasChildren returns \code true if the node has any children.
     * \return \code true if node has children.
     */
    virtual bool hasChildren() const {
        return !m_result_children.empty() || !m_letter_children.empty();
    }

    /*!
     * \brief resultChildren returns a reference to a list with result children.
     * We are using reference for perfomance reasons.
     * \return a reference to a list with result children.
     */
    QList<QSharedPointer<ResultNode>> &resultChildren() {
        return m_result_children;
    }

    /*!
     * \brief letterChildren returns a reference to a vector with letter
     * children. Implementation is dependent on a specific node type, and we
     * return reference to avoid inneficient copy constructors for \ref QVector
     *
     * \return a reference to a vector with letter children.
     */
    virtual QVector<QSharedPointer<LetterNode>> &letterChildren();

    /*!
     * \brief getLetterChild returns letter node child for given letter.
     * \param letter letter whose child is requested.
     * \return a letter node child or empty \ref QSharedPtr if it does not
     * exist.
     */
    virtual QSharedPointer<LetterNode> letterChild(const QChar &letter);

    /*!
     * \brief addChild adds a child to the node. The child will be wrapped in
     * \ref QSharedPointer
     * \param child a child to be added.
     */
    virtual void addChild(Node *child);

    /*!
     * \brief addChild adds a child to the node.
     * \param child a child to be addad.
     */
    virtual void addChild(QSharedPointer<Node> child);

    /*!
     * \brief removeChildren removes all childred from node.
     */
    virtual void removeChildren();

protected:
    QList<QSharedPointer<ResultNode>> m_result_children;
#if defined(BINARY_SEARCH)
    QVector<QSharedPointer<LetterNode>> m_letter_children;
#elif defined(HASH_TABLE)
    QHash<QChar, QSharedPointer<LetterNode>> m_letter_children
#elif defined(EXTENSIVE_TREE)
    QVector<QSharedPointer<LetterNode>> m_letter_children
#endif
};

#endif // BASENODE_H

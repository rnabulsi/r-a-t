#ifndef BASENODE_H
#define BASENODE_H

#include <QObject>
#include <QString>

/*!
 * \brief The BaseNode class is an abstract base class for all nodes.
 */
class BaseNode : public QObject {
    Q_OBJECT
public:
    /*!
     * \brief BaseNode the constructor.
     * \param parent a parent node.
     */
    explicit BaseNode(BaseNode *parent = nullptr);

    /*!
     * \brief BaseNode the copy constructor.
     * \param node the node to copy from.
     */
    explicit BaseNode(const BaseNode &node);

    /*!
     * \brief ~BaseNode the destructor.
     */
    virtual ~BaseNode();

    /*!
     * \brief operator = overloaded assignment operator.
     * \param node the node to assign from.
     * \return updated instance.
     */
    BaseNode &operator=(const BaseNode &node);

    /*!
     * \brief parent returns this nodes parent. This method is more consistent
     * with former \code getPrevious method.
     * \return parent node.
     */
    BaseNode *parent();

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
    virtual bool hasChildren() const = 0;

    /*!
     * \brief resultChildren returns a reference to a list with result children.
     * We are using reference for perfomance reasons.
     * \return a reference to a list with result children.
     */
    QList<BaseNode *> &resultChildren();

    /*!
     * \brief letterChildren returns a reference to a vector with letter
     * children. Implementation is dependent on a specific node type, and we
     * return reference to avoid inneficient copy constructors for \ref QVector
     *
     * \return a reference to a vector with letter children.
     */
    virtual QVector<BaseNode *> &letterChildren() = 0;

    /*!
     * \brief getLetterChild returns letter node child for given letter.
     * \param letter letter whose child is requested.
     * \return a letter node child of \code nullptr if it does not exist.
     */
    virtual BaseNode *getLetterChild(const QChar &letter) = 0;

    /*!
     * \brief addChild adds a child to the node.
     * \param child a child to be added.
     */
    virtual void addChild(BaseNode *child) = 0;

    virtual void resetChildren() = 0;
protected:
    /*!
     * \brief removeChildren removes all childred from node.
     */
    virtual void removeChildren() = 0;

private:
    QList<BaseNode *> m_result_children;
};

#endif // BASENODE_H

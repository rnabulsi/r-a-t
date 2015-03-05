#ifndef LETTERNODE_H
#define LETTERNODE_H

#include <QObject>
#include <node.h>

/*!
 * \brief The LetterNode class a specialized node that represents a letter.
 */
class LetterNode : public Node {
public:
    /*!
     * \brief LetterNode the constructor.
     * \param parent a parent node.
     */
    explicit LetterNode(Node *parent = nullptr) : Node(parent) {}

    /*!
     * \brief LetterNode the copy constructor.
     * \param node the node to copy from.
     */
    explicit LetterNode(const LetterNode &node) : Node(node) {
        m_letter = node.m_letter;
    }

    /*!
     * \brief LetterNode the constructor that intializes node with a letter.
     * \param letter a letter for the node.
     */
    explicit LetterNode(const QChar &letter) : Node(), m_letter(letter) {}

    /*!
     * \brief ~LetterNode the destructor.
     */
    virtual ~LetterNode() {}

    /*!
     * \brief operator = overloaded asignment operator.
     * \param node a node to assign from.
     * \return updated node.
     */
    LetterNode &operator=(const LetterNode &node) {
        m_letter = node.letter();
        m_result_children.clear();
        m_result_children = node.m_result_children;
        return *this;
    }

    /*!
     * \brief toString returns string representation of a node.
     * \return string representation of a node.
     */
    virtual QString toString(bool) const {
        return QString("--->(")
            .append((m_letter == '\0' ? '$' : m_letter))
            .append(")");
    }

    /*!
     * \brief letter returns this node's letter.
     * \return this node's letter.
     */
    inline QChar letter() const { return m_letter; }

    /*!
     * \brief setLetter sets this node's letter.
     * \param letter a letter to set.
     */
    inline void setLetter(const QChar &letter) { m_letter = letter; }

private:
    QChar m_letter;
};

/*!
 * \brief operator == equality operator.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter fields operands are equal.
 */
inline bool operator==(const LetterNode &left, const LetterNode &right) {
    return left.letter() == right.letter();
}

/*!
 * \brief operator != not equal operator
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter fields are not equal.
 */
inline bool operator!=(const LetterNode &left, const LetterNode &right) {
    return left.letter() != right.letter();
}

/*!
 * \brief operator < less than operator.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter from left operand is less
 * than the one from the right operand.
 */
inline bool operator<(const LetterNode &left, const LetterNode &right) {
    return left.letter() < right.letter();
}

/*!
 * \brief operator > greater than operator.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter from left operand is greater
 * than the one from the right operand.
 */
inline bool operator>(const LetterNode &left, const LetterNode &right) {
    return left.letter() > right.letter();
}

/*!
 * \brief operator <= less or equal operator.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter from left operand is less
 * than or equal to the one from the right operand.
 */
inline bool operator<=(const LetterNode &left, const LetterNode &right) {
    return !(left.letter() > right.letter());
}

/*!
 * \brief operator >= greater or equal operator.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter from left operand is greater
 * than or equal to the one from the right operand.
 */
inline bool operator>=(const LetterNode &left, const LetterNode &right) {
    return !(left.letter() < right.letter());
}

#endif // LETTERNODE_H

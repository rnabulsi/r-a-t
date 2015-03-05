#ifndef COMMON_H
#define COMMON_H

#include "common_global.h"

#include <QChar>
#include <QSharedPointer>
#include <node.h>
#include <letternode.h>

#if defined(BINARY_SEARCH)
/*!
 * \brief operator < less than operator that compares \ref LetterNode::m_letter
 * values. If left hand side operator is \ref nullptr we always return \code
 * true, and if right hand side operator is \ref nullptr we return \ref false if
 * left hand side operand is not \ref nullptr.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter of the left operand is less
 * than one from the right operand.
 */
inline bool operator<(const QSharedPointer<LetterNode> &left,
                      const QSharedPointer<LetterNode> &right) {
    return !left.isNull() && !right.isNull() &&
           left->letter() < right->letter();
}

/*!
 * \brief operator == equality operator that compares \ref LetterNode::m_letter
 * values. If both operands are \code nullptr \code true is returned.
 * \param left left hand side operand.
 * \param right right hand side operand.
 * \return \code true if \ref LetterNode::m_letter node of both operands is the
 * same, or both operands are \code nullptr.
 */
inline bool operator==(const QSharedPointer<LetterNode> &left,
                       const QSharedPointer<LetterNode> &right) {
    return !left.isNull() && !right.isNull() &&
           left->letter() == right->letter();
}

/*!
 * \brief binary_find Searching for value using binary search algorithm.
 * \param begin iterator defining the begin of a range.
 * \param end iterator defining the end of a range.
 * \param val value to find.
 * \return iterator pointing to \code val or \code end if \code val is not
 * found.
 */
template <class Iter, class T>
inline Iter binary_find(Iter begin, Iter end, T val) {
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}
#endif

#if defined(EXTENSIVE_TREE)
/*!
 * \brief letterIndex returns letter index when using extensive tree for storing letter node children.
 * \param letter a letter which position is required.
 * \return a letter position.
 */
inline int letterIndex(const QChar &letter) {
    int unicode = letter.unicode();
    if (unicode == 0)
        return 36;
    static int letter_map[42] = {
        0 /*0x621*/, 1,  2,  3,            4,  5,  6,  7,  8,  9,  10,
        11,          12, 13, 14,           15, 16, 17, 18, 19, 20, 21,
        22,          23, 24, 25 /*0x63A*/, -1, -1, -1, -1, -1, -1, 26 /*0x641*/,
        27,          28, 29, 30,           31, 32, 33, 34, 35};

    int diff = unicode - 1569 /*hamza.unicode()*/;
    if (!(diff > 0 && diff < 42))
        return -1;
    return letter_map[diff];
}
#endif

#endif // COMMON_H

#include <letternode.h>

LetterNode &LetterNode::operator=(const LetterNode &node) {
    Node::operator=(node);
    m_letter = node.letter();
    return *this;
}

QString LetterNode::toString(bool) const {
    return QString("--->(").append((m_letter == '\0' ? '$' : m_letter)).append(
        ")");
}

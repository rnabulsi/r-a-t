#include <resultnode.h>
#include <sqlmanager.h>

ResultNode::ResultNode(Node *parent)
    : Node(parent), m_previous_category_id(0), m_affix_id(0),
      m_resulting_category_id(DEFAULT_RESULTING_CATEGORY_ID),
      m_accept_state(true), m_inflection_rule(QString::null) {}

ResultNode::ResultNode(const ResultNode &node)
    : Node(node),
#ifdef REDUCE_THRU_DIACRITICS
      m_raw_data(node.rawData()),
#endif
      m_previous_category_id(node.m_previous_category_id),
      m_affix_id(node.m_affix_id),
      m_resulting_category_id(node.m_resulting_category_id),
      m_accept_state(node.m_accept_state),
      m_inflection_rule(node.m_inflection_rule) {
}

#if defined(REDUCE_THRU_DIACRITICS)
ResultNode::ResultNode(long affix_id, long previous_category_id,
                       long resulting_category_id, bool accept_state,
                       QString original, QString inflected)
    : Node(), m_previous_category_id(previous_category_id),
      m_affix_id(affix_id), m_resulting_category_id(resulting_category_id),
      m_accept_state(accept_state), m_inflection_rule(QString::null) {
    addRawData(original, inflected);
}

#else
ResultNode::ResultNode(long affix_id, long previous_category_id,
                       long resulting_category_id, bool accept_state)
    : Node(), m_previous_category_id(previous_category_id),
      m_affix_id(affix_id), m_resulting_category_id(resulting_category_id),
      m_accept_state(accept_state), m_inflection_rule(QString::null) {}
#endif

ResultNode &ResultNode::operator=(const ResultNode &node) {
    Node::operator=(node);
    m_previous_category_id = node.m_previous_category_id;
    m_affix_id = node.m_affix_id;
    m_resulting_category_id = node.m_resulting_category_id;
    m_accept_state = node.m_accept_state;
    m_inflection_rule = node.m_inflection_rule;
#ifdef REDUCE_THRU_DIACRITICS
    m_raw_data.append(node.m_raw_data);
#endif
    return *this;
}

ResultNode *ResultNode::previousResultNode() const {
    Node *previous = this->parent();
    while (previous != nullptr) {
        if (dynamic_cast<ResultNode *>(previous) != nullptr) {
            return dynamic_cast<ResultNode *>(previous);
        }
        previous = previous->parent();
    }
    return dynamic_cast<ResultNode *>(previous);
}

QString ResultNode::toString(bool isAffix) const {
    QString retVal("-%1>[%2]");
    retVal = retVal.arg(QString("%1").arg(
        isAffix ? SqlManager::instance().categoryName(m_previous_category_id)
                : QString("%1").arg(m_previous_category_id)));
    retVal = retVal.arg(QString("%1").arg(
        isAffix ? SqlManager::instance().categoryName(m_resulting_category_id)
                : QString("%1").arg(m_resulting_category_id)));
    return retVal;
}

void ResultNode::addRawData(QString original, QString inflected) {
    RawData rawData(original, inflected);
    if (!m_raw_data.contains(rawData)) {
        m_raw_data.append(rawData);
    }
}

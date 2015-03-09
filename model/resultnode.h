#ifndef RESULTNODE_H
#define RESULTNODE_H

#include <QObject>
#include <node.h>

/*!
 * \brief The ResultNode class a specialized node that represents result.
 */
class ResultNode : public Node {
public:
    static const long DEFAULT_RESULTING_CATEGORY_ID = 63;

    /*!
     * \brief ResultNode constructs \ref result node with given parent.
     * \param parent parent of the newly constructed node.
     */
    explicit ResultNode(Node *parent = nullptr);

    /*!
     * \brief ResultNode copy constructor.
     * \param node node to copy from.
     */
    explicit ResultNode(const ResultNode &node);
#if defined(REDUCE_THRU_DIACRITICS)
#else
    /*!
     * \brief ResultNode constructs \ref ResultNode with given parameters.
     * \param affix_id affix id
     * \param previous_category_id previous category id.
     * \param resulting_category_id resulting category id.
     * \param accept_state accept state.
     */
    ResultNode(long affix_id, long previous_category_id,
               long resulting_category_id, bool accept_state);
#endif
    /*!
     * \brief ~ResultNode the destructor.
     */
    virtual ~ResultNode() {}

    /*!
     * \brief operator = an overloaded assignment operator.
     * \param node node to assign from.
     * \return assigned instance.
     */
    ResultNode &operator=(const ResultNode &node);

    /*!
     * \brief toString returns string representation of the result node.
     * \param isAffix
     * \return string representation of the result node.
     */
    virtual QString toString(bool isAffix = true) const;

    /*!
     * \brief previousResultNode returns pointer to previous result node,
     * or \ref nullptr if such previous result node does not exist.
     * \return shared pointer to previous result node.
     */
    ResultNode *previousResultNode() const;

    /*!
     * \brief previousCategoryId returns previous category id.
     * \return previous category id.
     */
    long previousCategoryId() const { return m_previous_category_id; }

    /*!
     * \brief setPreviousCategoryId sets the id of the prevoius category.
     * \param id id to set.
     */
    void setPreviousCategoryId(long id) { m_previous_category_id = id; }

    /*!
     * \brief affixId returns the affix id.
     * \return affix id.
     */
    long affixId() const { return m_affix_id; }

    /*!
     * \brief setAffixId sets the affix id.
     * \param id id to set.
     */
    void setAffixId(long id) { m_affix_id = id; }

    /*!
     * \brief resultingCategoryId returns resulting category id.
     * \return resulting category id.
     */
    long resultingCategoryId() const { return m_resulting_category_id; }

    /*!
     * \brief setResultingCategoryId sets resulting category id.
     * \param id id to set.
     */
    void setResultingCategoryId(long id) { m_resulting_category_id = id; }

    /*!
     * \brief acceptState returns accept state.
     * \return accepts state.
     */
    bool acceptState() const { return m_accept_state; }

    /*!
     * \brief setAcceptState sets accept state.
     * \param state state to set.
     */
    void setAcceptState(bool state) { m_accept_state = state; }

    /*!
     * \brief inflectionRule returns const reference to inflection rule.
     * \return const reference to inflection rule.
     */
    const QString &inflectionRule() const { return m_inflection_rule; }

    /*!
     * \brief setInflectionRule sets inflection rule.
     * \param rule rule to set.
     */
    void setInflectionRule(const QString &rule) { m_inflection_rule = rule; }

private:
    /*!
     * \brief m_previous_category_id id of the previous category.
     */
    long m_previous_category_id;
    /*!
     * \brief m_affix_id id of the affix.
     */
    long m_affix_id;
    /*!
     * \brief m_resulting_category_id id of the resulting category. Default is
     * \code 63.
     */
    long m_resulting_category_id;
    /*!
     * \brief m_acceptState accept state. Default is \code true.
     */
    bool m_accept_state;
    /*!
     * \brief m_inflection_rule an inflection rule.
     */
    QString m_inflection_rule;
};

#endif // RESULTNODE_H

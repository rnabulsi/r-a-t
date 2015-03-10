#ifndef RAWDATA_HPP
#define RAWDATA_HPP

#include <QString>

/*!
 * \brief The RawData class represents raw data used in result nodes. It has
 * original and inflected string. If inflected string is equal to original then
 * inflected string is set to \code * during construction.
 */
class RawData {
public:
    /*!
     * \brief RawData constructs \ref RawData object.
     * \param original orignal string.
     * \param inflected inflected string.
     */
    RawData(const QString &original, const QString &inflected = "*") {
        m_original = original;
        m_inflected = (original == inflected) ? "*" : inflected;
    }

    /*!
     * \brief actual returns actual/resulting string. If string is not inflected
     * the original string is returned, otherwise inflected one is returned.
     * \return actual/resulting string.
     */
    QString actual() const {
        return m_inflected == "*" ? m_original : m_inflected;
    }

    /*!
     * \brief original returns original string.
     * \return original string.
     */
    QString original() const { return m_original; }

    /*!
     * \brief inflected return inflected string.
     * \return inflected string.
     */
    QString inflected() const { return m_inflected; }

    /*!
     * \brief operator == tests equality. Two \ref RawData instances are equal
     * only if both original and inflected strings are equal.
     * \param other instance to compare to.
     * \return \code true if instances are equal.
     */
    bool operator==(const RawData &other) const {
        return m_original == other.m_original &&
               m_inflected == other.m_inflected;
    }

private:
    /*!
     * \brief m_original original string.
     */
    QString m_original;
    /*!
     * \brief m_inflected inflected string.
     */
    QString m_inflected;
};

#endif // RAWDATA_HPP

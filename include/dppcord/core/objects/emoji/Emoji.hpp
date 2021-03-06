/**
 * @file Emoji.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 09:12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EMOJI_HPP
#define EMOJI_HPP
#include "dppcord/core/objects/IIdentifiableObject.hpp"
#include "dppcord/core/objects/INamedObject.hpp"

namespace dppcord
{
class User;
/**
     * @brief 
     * TODO: add roles
     */
class Emoji: public IIdentifiableObject, public INamedObject
{
public:
    /**
     * @brief Construct a new Emoji object with given json data
     * @param json data to construct the emoji from
     */
    Emoji(User& pUser, const nlohmann::json &emojijson);
    Emoji(const Emoji&) = default;
    /**
     * @brief Destroy the Emoji object
     */
    ~Emoji();
    /**
     * @brief Construct a new Emoji object without an owner user object
     * @param emojijson 
     */
    Emoji(const nlohmann::json& emojijson);

private:
    /**
     * @brief Construct a new Emoji object
     */
    Emoji();
    /**
     * @brief Creator of the emoji
     */
    User* m_user;

    /**
     * @brief Whether the emoji needs to be wrapped in colons or not
     */
    bool m_requiredColons;
    /**
     * @brief Whether this emoji is managed or not
     */
    bool m_managed;
    /**
     * @brief Whether this emoji is animated or not
     */
    bool m_animated;
};
} // namespace dppcord

#endif
/**
 * @file GuildChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 10:17
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDCHANNEL_HPP
#define GUILDCHANNEL_HPP

#include "BaseChannel.hpp"

namespace dppcord
{
class Guild;
class GuildChannel : public BaseChannel, public INamedObject
{
public:
    /**
     * @brief Construct a new Guild Channel object
     * @param pGuild pointer to the Guild object of this channel
     * @param channeljson data used to construct the channel
     */
    GuildChannel(Guild* pGuild, const nlohmann::json& channeljson);
    /**
     * @brief Destroy the Guild Channel object
     */
    ~GuildChannel();

    /**
     * @brief Returns a pointer to the guild this channel belongs to
     * @return Guild* 
     */
    Guild *getGuild();

protected:
    /**
     * @brief Construct a new Guild Channel object
     */
    GuildChannel();

    /**
     * @brief Guild this channel belongs to
     * Todo: some changes when channels get split
     */
    Guild *m_guild;

    /**
     * @brief whether the channel is nsfw
     */
    bool m_nsfw;
    
    /**
     * @brief Integer sorting position of this channel
     */
    int m_position;

    //Todo: add permission overwrites

    //Todo: add ParentId
private:
};
} // namespace dppcord

#endif
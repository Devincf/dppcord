/**
 * @file GuildRoleCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:00
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildRoleCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildRoleCreateEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildRoleCreateEvent proc\n";
        Guild& guild = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("id", eventPacket));
        m_forwardData.add(guild);
    }

}
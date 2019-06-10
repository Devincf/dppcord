/**
 * @file MessageUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/message/MessageUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void MessageUpdateEvent::proc(const nlohmann::json &eventPacket)
{
    //todo
    std::cout << "MessageUpdateEvent proc\n";
    //BaseMessage& message = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("guild_id", eventPacket)).getMessage(tryGetSnowflake("id", eventPacket));
    m_forwardData.add(eventPacket);
}

} // namespace dppcord
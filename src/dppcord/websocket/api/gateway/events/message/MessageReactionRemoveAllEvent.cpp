/**
 * @file MessageReactionRemoveAllEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/message/MessageReactionRemoveAllEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void MessageReactionRemoveAllEvent::proc(const nlohmann::json &eventPacket)
{
    //todo
    std::cout << "MessageReactionRemoveAllEvent proc\n";
        std::cout << eventPacket.dump(4) << '\n';
    //BaseMessage& message = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket)).getMessage(tryGetSnowflake("id", eventPacket));
    m_forwardData.add(eventPacket);
}

} // namespace dppcord
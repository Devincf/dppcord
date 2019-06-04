/**
 * @file MessageReactionAdd.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 04:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/MessageReactionAdd.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void MessageReactionAdd::proc(const nlohmann::json &eventPacket)
{
    //get message
    //if not nullptr procEvent.

    auto msg = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("guild_id", eventPacket))->getMessage(tryGetSnowflake("message_id", eventPacket));
    if(msg != nullptr)
        msg->reactionListener(eventPacket);

}

} // namespace dppcord


/*
{
    "channel_id": "550801436238282773",
    "emoji": {
        "animated": false,
        "id": null,
        "name": "🤔"
    },
    "guild_id": "439065048628068363",
    "message_id": "584569209611091980",
    "user_id": "142733073262444545"
}
*/
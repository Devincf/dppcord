/**
 * @file MessageDeleteEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-05 01:15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGEDELETEEVENT_HPP
#define MESSAGEDELETEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

namespace dppcord
{
class MessageDeleteEvent : public BaseEvent<int>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a MESSAGE_CREATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord


#endif
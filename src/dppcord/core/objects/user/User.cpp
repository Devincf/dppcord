/**
 * @file User.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/user/User.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
User::User() {}
User::~User() {}
User::User(const nlohmann::json &userjson)
{
    m_id = tryGetSnowflake("id",userjson);
    m_name = tryGetJson<std::string>("username",userjson);
    m_discriminator = tryGetJson<std::string>("discriminator",userjson);
    m_avatarHash = tryGetJson<std::string>("avatar",userjson);
    m_bot = tryGetJson<bool>("bot",userjson,false);
    m_mfaEnabled = tryGetJson<bool>("mfa_enabled",userjson);
    m_locale = tryGetJson<std::string>("locale",userjson);
    m_verified = tryGetJson<bool>("verified",userjson);
    m_email = tryGetJson<std::string>("email",userjson);
    m_flags = tryGetJson<int>("flages",userjson);
    m_premiumType = tryGetJson<int>("premium_type",userjson);
}

void User::sendDirect(const std::string& msg)
{
    auto id = DiscordEndpoint::createDM(std::to_string(m_id))["id"].get<std::string>();
    std::cout << DiscordEndpoint::sendMessage(id, msg) << '\n';
}

} // namespace dppcord
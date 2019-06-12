/**
 * @file DiscordEndpoint.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 04:21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/rest/Request.hpp"
#include "nlohmann/json.hpp"

#include <iostream>

namespace dppcord
{
std::string DiscordEndpoint::token = "";

void DiscordEndpoint::init(const std::string &itoken)
{
    token = itoken;
}

nlohmann::json DiscordEndpoint::sendMessage(const Snowflake &channelId, const std::string &content)
{
    return sendMessageExtended(channelId, {{"content", content}});
}

nlohmann::json DiscordEndpoint::sendMessageExtended(const Snowflake &channelId, const nlohmann::json &json)
{
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    RequestContent rc(json);

    auto response = Request::sendPOST( //this should be post?
        apiBase + "channels/" + std::to_string(channelId) + "/messages",
        rhl,
        rc);
    return nlohmann::json::parse(response.get());
}

bool DiscordEndpoint::deleteMessage(const std::string &channel, const std::string &id)
{
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);

    auto response = Request::sendDELETE(
        apiBase + "channels/" + channel + "/messages/" + id,
        rhl);
    if (response.get().size() != 0)
    {
        std::cout << "Error deleteMessage() : " << response.get() << '\n';
        return false;
    }
    return true;
}

bool DiscordEndpoint::createReaction(const std::string &channelId, const std::string &msgId, const std::string &emojiNameId)
{
    //PUT/channels/{channel.id}/messages/{message.id}/reactions/{emoji}/@me
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");
    auto response = Request::sendPUT(
        apiBase + "channels/" + channelId + "/messages/" + msgId + "/reactions/" + emojiNameId + "/@me",
        rhl);
    //nlohmann::json temp = nlohmann::json::parse(response.get());
    if (response.get().size() != 0)
    {
        std::cout << "Error createReaction() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::getGuild(const std::string &guildId)
{
    //GET/guilds/{guild.id}
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId,
        rhl);

    return nlohmann::json::parse(response.get());
}

nlohmann::json DiscordEndpoint::modifyGuild(const std::string &guildId, const nlohmann::json &guilddata)
{
    //PATCH/guilds/{guild.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(guilddata);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId,
        rhl,
        rc);

    return nlohmann::json::parse(response.get());
}

bool DiscordEndpoint::deleteGuild(const std::string &guildId)
{
    //TODO: Test together with createGuild
    //DELETE/guilds/{guild.id}
    RequestHeaderList rhl(token);

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId,
        rhl);

    if (response.get().size() != 0)
    {
        std::cout << "Error deleteGuild() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::getGuildChannels(const std::string &guildId)
{
    //GET/guilds/{guild.id}/channels

    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/channels",
        rhl);

    return nlohmann::json::parse(response.get());
}

nlohmann::json DiscordEndpoint::createGuildChannel(const std::string &guildId, const nlohmann::json &channeldata)
{
    //POST/guilds/{guild.id}/channels
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(channeldata);
    auto response = Request::sendPOST(
        apiBase + "guilds/" + guildId + "/channels",
        rhl,
        rc);

    return nlohmann::json::parse(response.get());
}

bool DiscordEndpoint::modifyGuildChannelPositions(const std::string &guildId, const nlohmann::json &channelarr)
{
    //PATCH/guilds/{guild.id}/channels
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(channelarr);
    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/channels",
        rhl,
        rc);
    if (response.get().size() != 0)
    {
        std::cout << "Error modifyGuildChannelPositions() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::getGuildUser(const std::string &guildId, const std::string &userId)
{
    //GET/guilds/{guild.id}/members/{user.id}
    //TODO: add Query String params
    RequestHeaderList rhl(token);
    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/members/" + userId,
        rhl);

    return nlohmann::json::parse(response.get());
}

nlohmann::json DiscordEndpoint::getGuildUserList(const std::string &guildId)
{
    //GET/guilds/{guild.id}/members
    RequestHeaderList rhl(token);
    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/members",
        rhl);

    return nlohmann::json::parse(response.get());
}

//TODO: Add Guild Member

bool DiscordEndpoint::modifyGuildMember(const std::string &guildId, const std::string &userId, const nlohmann::json &userdata)
{
    //PATCH/guilds/{guild.id}/members/{user.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(userdata);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/members/" + userId,
        rhl,
        rc);

    if (response.get().size() != 0)
    {
        std::cout << "Error modifyGuildMember() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::modifyCurrentNick(const std::string &guildId, const std::string &nickname)
{
    //PATCH/guilds/{guild.id}/members/@me/nick
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    nlohmann::json json = {{"nick", nickname}};
    RequestContent rc(json);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/members/@me/nick",
        rhl,
        rc);

    return nlohmann::json::parse(response.get());
}

bool DiscordEndpoint::addGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId)
{
    //PUT/guilds/{guild.id}/members/{user.id}/roles/{role.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");

    auto response = Request::sendPUT(
        apiBase + "guilds/" + guildId + "/members/" + userId + "/roles/" + roleId,
        rhl);

    if (response.get().size() != 0)
    {
        std::cout << "Error addGuildMemberRole() : " << response.get() << '\n';
        return false;
    }
    return true;
}

bool DiscordEndpoint::removeGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId)
{
    //DELETE/guilds/{guild.id}/members/{user.id}/roles/{role.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/members/" + userId + "/roles/" + roleId,
        rhl);

    if (response.get().size() != 0)
    {
        std::cout << "Error removeGuildMemberRole() : " << response.get() << '\n';
        return false;
    }
    return true;
}

bool DiscordEndpoint::removeGuildMember(const std::string &guildId, const std::string &userId)
{
    //DELETE/guilds/{guild.id}/members/{user.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/members/" + userId,
        rhl);

    if (response.get().size() != 0)
    {
        std::cout << "Error removeGuildMember() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::getGuildBans(const std::string &guildId)
{
    //GET/guilds/{guild.id}/bans
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/bans",
        rhl);
    return nlohmann::json::parse(response.get());
}

nlohmann::json DiscordEndpoint::getGuildBan(const std::string &guildId, const std::string &userId)
{
    //GET/guilds/{guild.id}/bans/{user.id}
    RequestHeaderList rhl;

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/bans/" + userId,
        rhl);
    return nlohmann::json::parse(response.get());
}

bool DiscordEndpoint::createGuildBan(const std::string &guildId, const std::string &userId, const nlohmann::json &bandata)
{
    //PUT/guilds/{guild.id}/bans/{user.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");
    RequestContent rc(bandata);

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/bans/" + userId,
        rhl,
        rc);

    if (response.get().size() != 0)
    {
        std::cout << "Error createGuildBan() : " << response.get() << '\n';
        return false;
    }
    return true;
}
bool DiscordEndpoint::removeGuildBan(const std::string &guildId, const std::string &userId)
{
    //DELETE/guilds/{guild.id}/bans/{user.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    rhl.addHeader("Content-Length:0");

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/bans/" + userId,
        rhl);

    if (response.get().size() != 0)
    {
        std::cout << "Error removeGuildBan() : " << response.get() << '\n';
        return false;
    }
    return true;
}

nlohmann::json DiscordEndpoint::getGuildRoles(const std::string &guildId)
{
    //GET/guilds/{guild.id}/roles
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/roles",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::createGuildRole(const std::string &guildId, const nlohmann::json &roledata)
{
    //POST/guilds/{guild.id}/roles
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(roledata);

    auto response = Request::sendPOST(
        apiBase + "guilds/" + guildId + "/roles",
        rhl,
        rc
    );

    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::modifyGuildRolePositions(const std::string &guildId, const nlohmann::json &rolearr)
{
    //PATCH/guilds/{guild.id}/roles
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(rolearr);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/roles",
        rhl,
        rc
    );

    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::modifyGuildRole(const std::string &guildId, const std::string& roleId, const nlohmann::json &roledata)
{
    //PATCH/guilds/{guild.id}/roles/{role.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(roledata);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/roles/" + roleId,
        rhl,
        rc
    );

    return nlohmann::json::parse(response.get());
}
bool DiscordEndpoint::deleteGuildRole(const std::string &guildId, const std::string &roleId)
{
    //DELETE/guilds/{guild.id}/roles/{role.id}
    RequestHeaderList rhl(token);
    rhl.addHeader("Content-Lenght: 0");

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/roles/" + roleId,
        rhl
    );

    if(response.get().size() != 0)
    {
        std::cout << "Error deleteGuildRole() : " << response.get() << '\n';
        return false;
    }

    return true;
}
nlohmann::json DiscordEndpoint::getGuildPruneCount(const std::string &guildId, const int days)
{
    //GET/guilds/{guild.id}/prune
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/prune",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::beginGuildPrune(const std::string &guildId, const int days, const bool compute_prune_count)
{
    //POST/guilds/{guild.id}/prune
    RequestHeaderList rhl(token, REQUESTCONTENT_MULTIPART_FORMDATA);
    const nlohmann::json json({{"days", days}, "compute_prune_count", compute_prune_count});
    RequestContent rc(json);

    auto response = Request::sendPOST(
        apiBase + "guilds/" + guildId + "/prune",
        rhl,
        rc
    );

    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::getGuildVoiceRegions(const std::string &guildId)
{
    //GET/guilds/{guild.id}/regions
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/regions",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::getGuildInvites(const std::string &guildId)
{
    //GET/guilds/{guild.id}/invites
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/invites",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::getGuildIntegrations(const std::string &guildId)
{
    //GET/guilds/{guild.id}/integrations
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/integrations",
        rhl);
    return nlohmann::json::parse(response.get());
}
bool DiscordEndpoint::createGuildIntegration(const std::string &guildId, const std::string &type, const std::string &id)
{
    //TODO: fix
    //POST/guilds/{guild.id}/integrations
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    nlohmann::json data = {{"type", type}, {"id", id}};
    RequestContent rc(data);

    auto response = Request::sendPOST(
        apiBase + "guilds/" + guildId + "/integrations",
        rhl,
        rc
    );

    if(response.get().size() != 0)
    {
        std::cout << "Error createGuildIntegration() : " << response.get() << '\n';
        return false;
    }

    return true;
}
bool DiscordEndpoint::modifyGuildIntegration(const std::string &guildId, const std::string& integrationId, const nlohmann::json &integrationdata)
{
    //TODO: fix
    //PATCH/guilds/{guild.id}/integrations/{integration.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc(integrationdata);

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/integrations/" + integrationId,
        rhl,
        rc
    );

    if(response.get().size() != 0)
    {
        std::cout << "Error modifyGuildIntegration() : " << response.get() << '\n';
        return false;
    }

    return true;
}
bool DiscordEndpoint::deleteGuildIntegration(const std::string &guildId, const std::string &integrationId)
{
    //TODO: fix
    //DELETE/guilds/{guild.id}/integrations/{integration.id}
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    rhl.addHeader("Content-Length: 0");
    

    auto response = Request::sendDELETE(
        apiBase + "guilds/" + guildId + "/integrations/" + integrationId,
        rhl
    );

    if(response.get().size() != 0)
    {
        std::cout << "Error deleteGuildIntegration() : " << response.get() << '\n';
        return false;
    }

    return true;
}
bool DiscordEndpoint::syncGuildIntegration(const std::string &guildId, const std::string &integrationId)
{
    //TODO: fix
    //POST/guilds/{guild.id}/integrations/{integration.id}/sync
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);

    auto response = Request::sendPOST(
        apiBase + "guilds/" + guildId + "/integrations/" + integrationId,
        rhl
    );

    if(response.get().size() != 0)
    {
        std::cout << "Error syncGuildIntegration() : " << response.get() << '\n';
        return false;
    }

    return true;
}
nlohmann::json DiscordEndpoint::getGuildEmbed(const std::string &guildId)
{
    //GET/guilds/{guild.id}/embed

    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/embed",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::modifyGuildEmbed(const std::string &guildId, const nlohmann::json &embeddata)
{
    //PATCH/guilds/{guild.id}/embed
    RequestHeaderList rhl(token, REQUESTCONTENT_APPLICATION_JSON);
    RequestContent rc;

    auto response = Request::sendPATCH(
        apiBase + "guilds/" + guildId + "/embed",
        rhl,
        rc
    );

    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::getGuildVanityURL(const std::string &guildId)
{
    //GET/guilds/{guild.id}/vanity-url
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/vanity-url",
        rhl);
    return nlohmann::json::parse(response.get());
}
nlohmann::json DiscordEndpoint::getGuildWidgetImage(const std::string &guildId, const std::string &&style)
{
    //GET/guilds/{guild.id}/widget.png
    RequestHeaderList rhl(token);

    auto response = Request::sendGET(
        apiBase + "guilds/" + guildId + "/widget.png",
        rhl);
    
    /* TODO: somehow implement this lol
    std::string s = response.get();
    FILE *File = NULL;
    File = fopen("Image.png", "wb"); //Note b for binary mode
    if (File == NULL)
    {
        return 1;
    }                                                                          //Error
    if (fwrite(s.c_str(), s.size(), 1, File) != s.size()) //If there is a mismatch between the amount of data written and the string size, we have an error
    {
        perror("File write error occurred"); //Needs errno
        fclose(File);
        return 2;
    }

    fclose(File);*/
    return nlohmann::json();
}

} // namespace dppcord
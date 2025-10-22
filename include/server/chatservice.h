#pragma once

#include "json.hpp"
using json = nlohmann::json;

#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include <functional>
#include <string>

using namespace muduo;
using namespace muduo::net;

// 处理消息的事件回调方法类型
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;

// 聊天服务器业务类
class ChatService
{
public:
public:
    // 获取单例对象接口
    static ChatService *instance();
    // 处理登陆业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);

    // 处理注册业务
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);

    // 获取消息对应的处理器
    MsgHandler getHandler(int msgid);
private:
    ChatService();

    // 存储消息id和其对应的业务处理方法
    std::unordered_map<int, MsgHandler> MsgHandlerMap_;
};
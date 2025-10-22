#include "chatserver.h"

#include <functional>
using namespace std::placeholders;

ChatServer::ChatServer(EventLoop *loop,
                       const InetAddress &listenAddr,
                       const string &nameArg)
    : server_(loop, listenAddr, nameArg), loop_(loop)
{
    // 注册连接回调
    server_.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));

    // 注册消息回调
    server_.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

    // 设置线程数量
    server_.setThreadNum(4);
}

// 启动服务
void ChatServer::start()
{
    server_.start();
}

// 上报连接相关信息的回调函数
void ChatServer::onConnection(const TcpConnectionPtr &conn)
{ 
}

// 上报读写时间相关信息的回调函数
void ChatServer::onMessage(const TcpConnectionPtr &conn,
                            Buffer *buffer,
                            Timestamp time)
{
}
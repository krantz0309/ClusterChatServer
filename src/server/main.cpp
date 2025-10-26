#include "chatserver.h"
#include "chatservice.h"
#include <iostream>
#include <signal.h>

using namespace std;

// 处理服务器ctrl+c退出后，重置user状态信息
void resetHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}

int main()
{
    EventLoop loop;
    InetAddress addr("127.0.0.1", 6000);
    ChatServer server(&loop, addr, "ChatServer");
    server.start();
    loop.loop();
    return 0;
}
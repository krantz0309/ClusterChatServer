# ClusterChatServer

## Project Overview

High-performance clusterchatserver, implemented based on the muduo.

1.Using muduo as the core network module to provide high-concurrency network IO services.

2.Configure Nginx TCP-based load balancing to implement clustering and improve backend concurrency.

3.Based on Redis's publish-subscribe functionality, cross-server communication is achieved.

## Version(for reference only, not required)

1.muduo( https://github.com/chenshuo/muduo)

2.redis/hiredis(https://github.com/redis/hiredis)

3.json(https://github.com/nlohmann/json)

4.WSL: Ubuntu 24.04.3

5.nginx 1.24.0

6.mysql 8.0.43

7.g++ 13.3.0

8.cmake 3.28.3

## Quick Start

```bash
# permission(required for the first run)
chmod +x autobuild.sh

# run autobuild.sh
./autobuild.sh

# run the generated executable file
cd bin
# run on several available ports
./ChatServer 127.0.0.1 6000
./ChatServer 127.0.0.1 6002
# run ChatClient on the port listened by nginx
# read /usr/local/nginx/conf/nginx.conf to check for configurations
./ChatClient 127.0.0.1 80
```


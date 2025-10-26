#pragma once

#include <string>
#include <mysql/mysql.h>

// 数据库操作类
class MySQL
{
public:
    // 初始化数据库连接
    MySQL()
    {
        conn_ = mysql_init(nullptr);
    }
    // 释放数据库连接资源
    ~MySQL()
    {
        if (conn_ != nullptr)
        {
            mysql_close(conn_);
        }
    }
    // 连接数据库
    bool connect();
    // 更新操作
    bool update(std::string sql);
    // 查询操作
    MYSQL_RES *query(std::string sql);
    // 获取连接
    MYSQL *getConnection();

private:
    MYSQL *conn_;
};
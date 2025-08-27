//#include <mysql_driver.h>
//#include <mysql_connection.h>
//#include <cppconn/statement.h>
//
//using namespace sql;

//#define DEBUG
#ifdef DEBUG

int main() {
    try {
        // 创建 MySQL 连接
        mysql::MySQL_Driver* driver;
        Connection* con;

        driver = mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");

        // 选择数据库
        con->setSchema("test_db");

        // 执行查询
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT * FROM users");

        // 输出结果
        while (res->next()) {
            std::cout << "ID: " << res->getInt("id")
                << ", Name: " << res->getString("name") << std::endl;
        }

        // 释放资源
        delete res;
        delete stmt;
        delete con;
    }
    catch (SQLException& e) {
        std::cerr << "MySQL Error: " << e.what() << std::endl;
    }
    return 0;
}

#endif // DEBUG


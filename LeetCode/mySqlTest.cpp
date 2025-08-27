//#include <mysql_driver.h>
//#include <mysql_connection.h>
//#include <cppconn/statement.h>
//
//using namespace sql;

//#define DEBUG
#ifdef DEBUG

int main() {
    try {
        // ���� MySQL ����
        mysql::MySQL_Driver* driver;
        Connection* con;

        driver = mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");

        // ѡ�����ݿ�
        con->setSchema("test_db");

        // ִ�в�ѯ
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT * FROM users");

        // ������
        while (res->next()) {
            std::cout << "ID: " << res->getInt("id")
                << ", Name: " << res->getString("name") << std::endl;
        }

        // �ͷ���Դ
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


#include <vector>
#include <iostream>
#include "PhoneBook.h"
#include "PhoneEntry.h"

PhoneBook::PhoneBook() {

}
  vector<PhoneEntry> PhoneBook::findByLast(string last) {
    sql::Driver* driver = sql::mysql::get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, pass));
    con->setSchema(database);
    std::auto_ptr<sql::Statement> stmt(con->createStatement());

    vector<PhoneEntry> list;
    stmt->execute("CALL find_last('%"+last+"%')");
    std::auto_ptr< sql::ResultSet > res;
    do {
      res.reset(stmt->getResultSet());
      while (res->next()) {
          PhoneEntry entry(res->getString("First"),res->getString("Last"),
			   res->getString("Phone"),res->getString("Type"),
			   res->getString("RecNum"));
          list.push_back(entry);

      }
    } while (stmt->getMoreResults());
    return list;
    
}

#include <iostream>

#include <sqlite_modern_cpp.h>

sqlite::database& get_database() {
    static sqlite::database database("database.sqlite");
    return database;
}

void create_test_database() {

}

int main () {


}


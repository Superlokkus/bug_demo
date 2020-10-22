#include <iostream>

#include <optional>

#include <sqlite_modern_cpp.h>

sqlite::database& get_database() {
    static sqlite::database database("database.sqlite");
    return database;
}

void create_test_database() {
    auto db = get_database();

    db << "CREATE TABLE IF NOT EXISTS test (id integer not null primary key, opt_field real null) without rowid;";

}

void insert_data() {
    long id {1337};
    auto opt_field = std::optional<double>(4.2);
    auto db = get_database();

    db << "insert or replace into test(id,opt_field) values (?,?);"
    << id << opt_field;
}



int main () {
    create_test_database();
    insert_data();

}


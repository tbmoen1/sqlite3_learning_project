//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//

#include "DatabaseRepository.h"
#include <filesystem>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <sys/_types/_uuid_t.h>

#include "../../domain/PressedKey.h"

class PressedKey;
auto dbFileName = "sqlite3.db"; // auto resolves to const char*
sqlite3* db;
int rc;

void InitializeDb() {
    // sqlite3_open creates or opens db file if it does not exist,
    // TryGetDb() is just something i made for fun
    const bool dbExists = TryGetDb();

    if (sqlite3_open(dbFileName, &db)) {
        printf("Database could not be opened %s \n", sqlite3_errmsg(db));
        return;
    }

    if (!dbExists) {
        printf("New database created, running migrations\n");

    } else {
        printf("Opened existing database\n");
    }
}

namespace fs = std::filesystem;
bool TryGetDb() {
    bool exists;
    fs::path filePath = dbFileName; // Specify filename as the global dbFileName const

    // If filepath exists, return true. If not, return false
    if (fs::exists(filePath)) {
        exists = true;
    } else {
        exists = false;
    }
    return exists;
}

int InsertKeyPress(PressedKey& pressedKey) {
    std::string sql = PressedKey::insert_key_sql;
    sqlite3_stmt* statement;

    rc = sqlite3_prepare_v2(db, sql.c_str(), strlen(sql.c_str()), &statement, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    // Deserialize uuid_t from class into string for db insert
    char idStr[37];
    uuid_unparse(pressedKey.id, idStr);

    const std::string key = pressedKey.key;

    // same with timestamp, assign to t -> deserialize to string for db insert
    const auto t = std::chrono::system_clock::to_time_t(pressedKey.timesStamp);
    const auto tsStr = std::string(std::ctime(&t));

    sqlite3_bind_text(statement, 1, idStr, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 2, key.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 3, tsStr.c_str(), -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(statement);
    if (rc == SQLITE_DONE) {
        std::cout << "Data inserted successfully!" << std::endl;
        return SQLITE_OK;
    }
    // Else
    std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
    return SQLITE_ERROR;
}

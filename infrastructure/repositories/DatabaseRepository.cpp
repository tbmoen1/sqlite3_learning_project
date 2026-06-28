//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//

#include "DatabaseRepository.h"
#include <filesystem>
#include <sqlite3.h>
#include <string>

auto dbFileName = "database.sqlite3"; // auto resolves to const char*
sqlite3* db;

void InitializeDb(sqlite3* database) {
    // sqlite3_open creates or opens db file if it does not exist,
    // TryGetDb() is just something i made for fun
    bool dbExists = TryGetDb();
    int opened = sqlite3_open(dbFileName, &database);

    if (opened) {
        printf("Database could not be opened %s \n", sqlite3_errmsg(database));
        return;
    }

    db = database;
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

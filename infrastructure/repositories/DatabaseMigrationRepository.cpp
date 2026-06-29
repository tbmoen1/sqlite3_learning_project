//
// Created by Thomas Bekkedal Moen on 29/06/2026.
//

#include "DatabaseMigrationRepository.h"

#include <iostream>
#include <sqlite3.h>
#include "../../domain/PressedKey.h"
#include <string>

// TODO: Create a HasPendingChanged(sqlite3db db, std::string check_if_table_exists_query)
// Overload to support bring-your-own-query instead of hardcoding each query into method
// (or loop through each class that implements a ModelInterface which contains "std::string check_if_table_exists_sql"
// -> run the query per class to dynamically check if each class registered exist / out of sync)


/**
 * Method to check if local database is out of sync
 * @param db Db to check if has any pending changes
 * @return True/False
 */
bool HasPendingChanges(sqlite3* db) {
    const std::string sql = PressedKey::check_if_table_exists_sql;
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) == SQLITE_OK) {
        // Loop through each row in the result set and return true if any found
        const bool exists =  sqlite3_step(statement) == SQLITE_ROW;
        return !exists; // Return opposite of exists. If any rows found, db does not have pending changes
    }
    std::cerr << "Failed to prepare select statement: " << sqlite3_errmsg(db) << std::endl;
    return true;
}

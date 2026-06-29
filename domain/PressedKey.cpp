//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//
#include "PressedKey.h"

auto table_name = "pressedKeys";
const std::string check_if_table_exists_sql =
    std::format("SELECT name FROM sqlite_master WHERE type='table' AND name='{}';", table_name);

const std::string insert_key_sql =
    std::format("INSERT INTO {} (id, key, timeStamp) VALUES (?, ?, ?);", table_name);

const std::string create_table_sql = std::format(
        "CREATE TABLE IF NOT EXISTS {} ("
        "id TEXT PRIMARY KEY,"
        "key TEXT NOT NULL,"
        "timeStamp TEXT NOT NULL"
        ");",
        table_name);


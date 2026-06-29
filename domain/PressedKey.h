//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//
#pragma once
#include <chrono>
#include <string>
#include <uuid/uuid.h>

#ifndef UNTITLED_PRESSEDKEY_H
#define UNTITLED_PRESSEDKEY_H

class PressedKey {
public:
    uuid_t id = {};
    std::string key;
    std::chrono::time_point<std::chrono::system_clock> timesStamp;

    // Query to create needed table
    static std::string create_table_sql;

    // Query to run to insert a key
    static std::string insert_key_sql;

    // Query to run to determine if local db is out of sync
    static std::string check_if_table_exists_sql;
};
#endif //UNTITLED_PRESSEDKEY_H

//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//
#include <string>
#include <uuid/uuid.h>

class PressedKey {
    uuid_t id = {};
    std::string key;
    std::chrono::time_point<std::chrono::system_clock> timesStamp;
};

//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//
#pragma once
#include <string>
#include <uuid/uuid.h>

#ifndef UNTITLED_PRESSEDKEY_H
#define UNTITLED_PRESSEDKEY_H

class PressedKey {
public:
    uuid_t id = {};
    std::string key;
    std::chrono::time_point<std::chrono::system_clock> timesStamp;
};
#endif //UNTITLED_PRESSEDKEY_H

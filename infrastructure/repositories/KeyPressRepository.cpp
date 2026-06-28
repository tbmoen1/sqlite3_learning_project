//
// Created by Thomas Bekkedal Moen on 28/06/2026.
//

#include "KeyPressRepository.h"
#include "../../domain/PressedKey.h"

#include <chrono>
#include <sys/_types/_uuid_t.h>
#include <uuid/uuid.h>


void OnKeyPress(const char* key) {
    // Generate Database id
    uuid_t id;
    uuid_generate_random(id);

    // Generate timestamp
    const std::chrono::time_point<std::chrono::system_clock> timeStamp = std::chrono::system_clock::now();

    // Create DB Model to insert
    PressedKey pressedKey;
    uuid_copy(pressedKey.id, id); // uuid_copy handles assignement
    pressedKey.timesStamp = timeStamp;
    pressedKey.key = key;
}

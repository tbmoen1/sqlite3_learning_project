cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

find_package(SQLite3 REQUIRED)

add_executable(untitled main.cpp
        domain/PressedKey.cpp
        domain/PressedKey.h
        infrastructure/repositories/KeyPressRepository.cpp
        infrastructure/repositories/KeyPressRepository.h
        infrastructure/repositories/DatabaseRepository.cpp
        infrastructure/repositories/DatabaseRepository.h
        infrastructure/repositories/DatabaseMigrationRepository.cpp
        infrastructure/repositories/DatabaseMigrationRepository.h
)

target_link_libraries(untitled PRIVATE SQLite::SQLite3)

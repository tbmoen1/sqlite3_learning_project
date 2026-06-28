cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        api/users/UserController.cpp
        api/users/UserController.h
        domain/PressedKey.cpp
        infrastructure/repositories/KeyPressRepository.cpp
        infrastructure/repositories/KeyPressRepository.h
        domain/PressedKey.h
        infrastructure/repositories/DatabaseRepository.cpp
        infrastructure/repositories/DatabaseRepository.h
)

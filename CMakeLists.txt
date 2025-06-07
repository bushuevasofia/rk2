cmake_minimum_required(VERSION 3.14)
project(rk2 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем include директорию для всего проекта
include_directories(${CMAKE_SOURCE_DIR}/include)

# Библиотека MessageHandler
add_library(MessageHandler STATIC
    src/MessageHandler.cpp
    src/DefaultState.cpp
    src/SessionState.cpp
)

# Исполняемый файл
add_executable(message_handler_app app/main.cpp)
target_link_libraries(message_handler_app PRIVATE MessageHandler)

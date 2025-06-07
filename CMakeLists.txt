cmake_minimum_required(VERSION 3.14)
project(MessageHandlerProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Включаем тестирование
option(BUILD_TESTS "Build unit tests" ON)

# Добавляем пути к заголовкам
include_directories(${PROJECT_SOURCE_DIR}/include)

# Библиотека
add_library(messagehandler STATIC src/MessageHandler.cpp)
target_include_directories(messagehandler PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(message_handler_app app/main.cpp)
target_link_libraries(message_handler_app PRIVATE messagehandler)

# Тесты
if(BUILD_TESTS)
    enable_testing()

    include(FetchContent)

    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip 
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()

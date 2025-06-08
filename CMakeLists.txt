cmake_minimum_required(VERSION 3.11)
project(state_pattern)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем статическую библиотеку
add_library(state_pattern STATIC
    src/message_handler.cpp
    src/default_state.cpp
    src/session_state.cpp
)

# Устанавливаем заголовочные файлы
target_include_directories(state_pattern PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Создаем исполняемый файл
add_executable(state_pattern_demo main.cpp)
target_link_libraries(state_pattern_demo state_pattern)

# Включаем тестирование
enable_testing()

# Добавляем поддиректорию с тестами
add_subdirectory(tests)

# Установка
install(TARGETS state_pattern
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)
install(TARGETS state_pattern_demo RUNTIME DESTINATION bin)

# Настройка CPack для создания DEB пакета
set(CPACK_PACKAGE_NAME "state-pattern")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "State Pattern Implementation")
set(CPACK_PACKAGE_CONTACT "your.email@example.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
set(CPACK_GENERATOR "DEB")

include(CPack)

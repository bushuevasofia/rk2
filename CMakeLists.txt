cmake_minimum_required(VERSION 3.14)
project(MessageHandler VERSION 1.0 LANGUAGES CXX)

# Обязательные настройки для CPack
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(GNUInstallDirs)

# Основная библиотека
add_library(MessageHandler STATIC
    src/MessageHandler.cpp
    src/DefaultState.cpp
    src/SessionState.cpp
)
target_include_directories(MessageHandler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Исполняемый файл
add_executable(message_handler app/main.cpp)
target_link_libraries(message_handler PRIVATE MessageHandler)

# Установка файлов
install(TARGETS message_handler
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS MessageHandler
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Настройка DEB-пакета
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "message-handler")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "Your Name <your.email@example.com>")
set(CPACK_PACKAGE_DESCRIPTION "Message handler application")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27)")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)  # Автоимя файла
include(CPack)

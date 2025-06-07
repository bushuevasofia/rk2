# Список исходных файлов
set(SRC_FILES
    MessageHandler.cpp
    DefaultState.cpp
    SessionState.cpp
)

# Проверка существования файлов
foreach(file IN LISTS SRC_FILES)
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        message(FATAL_ERROR "Source file ${file} not found in src directory!")
    endif()
endforeach()

add_library(MessageHandler STATIC ${SRC_FILES})
target_include_directories(MessageHandler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

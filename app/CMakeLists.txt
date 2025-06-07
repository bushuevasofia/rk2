if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    message(FATAL_ERROR "main.cpp not found in app directory!")
endif()

add_executable(message_handler_app main.cpp)
target_link_libraries(message_handler_app PRIVATE MessageHandler)

install(TARGETS message_handler_app
    RUNTIME DESTINATION bin
)

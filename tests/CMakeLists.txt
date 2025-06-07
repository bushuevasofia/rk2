find_package(GTest REQUIRED)

add_executable(test_messagehandler TestMessageHandler.cpp)
target_link_libraries(test_messagehandler PRIVATE MessageHandler GTest::GTest)
add_test(NAME test_messagehandler COMMAND test_messagehandler)

# Аналогично для других тестов

add_executable(test_messagehandler test_messagehandler.cpp)
target_link_libraries(test_messagehandler
    PRIVATE
    GTest::gtest_main
    GTest::gmock_main
    messagehandler
)
add_test(NAME test_messagehandler COMMAND test_messagehandler)

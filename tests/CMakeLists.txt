# Поиск GTest
find_package(GTest REQUIRED)

# Тест для DefaultState
add_executable(test_default_state test_default_state.cpp)
target_link_libraries(test_default_state state_pattern GTest::GTest GTest::Main)
add_test(NAME test_default_state COMMAND test_default_state)

# Тест для SessionState
add_executable(test_session_state test_session_state.cpp)
target_link_libraries(test_session_state state_pattern GTest::GTest GTest::Main)
add_test(NAME test_session_state COMMAND test_session_state)

#include "state_pattern/session_state.h"
#include "state_pattern/default_state.h"
#include <gtest/gtest.h>

TEST(SessionStateTest, HandleEndSession) {
    SessionState state("test_session");
    auto result = state.HandleMessage("end_session");
    ASSERT_NE(result, nullptr);
    auto defaultState = dynamic_cast<DefaultState*>(result.get());
    EXPECT_NE(defaultState, nullptr);
}

TEST(SessionStateTest, HandlePrintMessage) {
    SessionState state("test_session");
    auto result = state.HandleMessage("print hello");
    EXPECT_EQ(result, nullptr);
}

TEST(SessionStateTest, HandleInvalidMessage) {
    SessionState state("test_session");
    auto result = state.HandleMessage("invalid");
    EXPECT_EQ(result, nullptr);
}

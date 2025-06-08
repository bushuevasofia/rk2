#include "state_pattern/default_state.h"
#include "state_pattern/session_state.h"
#include <gtest/gtest.h>

TEST(DefaultStateTest, HandleInvalidMessage) {
    DefaultState state;
    auto result = state.HandleMessage("invalid");
    EXPECT_EQ(result, nullptr);
}

TEST(DefaultStateTest, HandleStartSession) {
    DefaultState state;
    auto result = state.HandleMessage("start_session test_session");
    ASSERT_NE(result, nullptr);
    auto sessionState = dynamic_cast<SessionState*>(result.get());
    EXPECT_NE(sessionState, nullptr);
}

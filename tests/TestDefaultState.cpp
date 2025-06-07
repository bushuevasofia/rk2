#include <gtest/gtest.h>
#include "MessageHandler/DefaultState.h"
#include <sstream>

TEST(DefaultStateTest, StartsSession) {
    MessageHandler::DefaultState state;
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    auto result = state.HandleMessage("start_session test");
    
    std::cout.rdbuf(old);
    EXPECT_NE(result, nullptr);
    EXPECT_NE(buffer.str().find("[Start Session] Session Name : test"), std::string::npos);
}

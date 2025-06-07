#include <gtest/gtest.h>
#include "MessageHandler/MessageHandler.h"
#include <sstream>

class MessageHandlerTest : public ::testing::Test {
protected:
    MessageHandler::MessageHandler handler;
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    void TearDown() override {
        std::cout.rdbuf(old);
    }
};

TEST_F(MessageHandlerTest, HandlesInvalidMessage) {
    handler.HandleMessage("invalid");
    EXPECT_NE(buffer.str().find("\"invalid\" is invalid message."), std::string::npos);
}

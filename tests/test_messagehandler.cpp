#include <gtest/gtest.h>
#include "MessageHandler.h"

TEST(MessageHandlerTest, InvalidMessage_DefaultState) {
    testing::internal::CaptureStdout();
    MessageHandler handler;
    handler.HandleMessage("invalid");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("\"invalid\" is invalid message."), std::string::npos);
}

TEST(MessageHandlerTest, StartSession) {
    MessageHandler handler;
    handler.HandleMessage("start_session TestSession");
    // Проверка поведения можно сделать через mock или проверку вывода
}

TEST(MessageHandlerTest, EndSession) {
    MessageHandler handler;
    handler.HandleMessage("start_session TestSession");
    handler.HandleMessage("end_session");
    // Аналогично: проверить вывод или состояние
}

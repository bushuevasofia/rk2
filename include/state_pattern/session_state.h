#pragma once
#include "state_pattern/message_handler.h"
#include <memory>
#include <string>

class SessionState : public MessageHandler::State {
public:
    explicit SessionState(std::string sessionName);
    std::unique_ptr<MessageHandler::State> HandleMessage(const std::string& message) override;

private:
    std::string sessionName_;
};

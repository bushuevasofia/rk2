#pragma once
#include "state_pattern/message_handler.h"
#include <memory>
#include <string>

class DefaultState : public MessageHandler::State {
public:
    std::unique_ptr<MessageHandler::State> HandleMessage(const std::string& message) override;
};

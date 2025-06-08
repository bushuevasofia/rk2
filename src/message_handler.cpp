#include "state_pattern/message_handler.h"
#include "state_pattern/default_state.h"

MessageHandler::MessageHandler() : state_(std::make_unique<DefaultState>()) {}

void MessageHandler::HandleMessage(const std::string& message) {
    auto newState = state_->HandleMessage(message);
    if (newState) {
        state_ = std::move(newState);
    }
}

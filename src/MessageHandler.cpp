#include "MessageHandler/MessageHandler.h"
#include "MessageHandler/DefaultState.h"

namespace MessageHandler {

MessageHandler::MessageHandler() : state_(std::make_unique<DefaultState>()) {}

void MessageHandler::HandleMessage(const std::string& message) {
    auto newState = state_->HandleMessage(message);
    if (newState) {
        state_ = std::move(newState);
    }
}

} 

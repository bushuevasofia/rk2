#include "MessageHandler/SessionState.h"
#include "MessageHandler/DefaultState.h"
#include <iostream>
#include <algorithm>

namespace MessageHandler {

SessionState::SessionState(std::string sessionName) 
    : sessionName_(std::move(sessionName)) {}

std::unique_ptr<State> SessionState::HandleMessage(const std::string& message) {
    const std::string kPrintCommand("print ");
    if (message == "end_session") {
        std::cout << "[" << sessionName_ << "][End Session]" << std::endl;
        return std::make_unique<DefaultState>();
    }
    if (message.compare(0, kPrintCommand.size(), kPrintCommand) == 0) {
        auto it = std::next(message.begin(), kPrintCommand.size());
        std::string text(it, message.end());
        std::cout << "[" << sessionName_ << "][Print] " << text << std::endl;
    } else {
        std::cout << "[" << sessionName_ << "] \"" << message << "\" is invalid message." << std::endl;
    }
    return nullptr;
}

} 

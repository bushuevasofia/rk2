#include "state_pattern/session_state.h"
#include "state_pattern/default_state.h"
#include <iostream>
#include <algorithm>

SessionState::SessionState(std::string sessionName) : sessionName_(std::move(sessionName)) {}

std::unique_ptr<MessageHandler::State> SessionState::HandleMessage(const std::string& message) {
    const std::string kPrintCommand("print ");

    if (message == "end_session") {
        std::cout << "[" << sessionName_ << "][End Session]" << std::endl;
        return std::make_unique<DefaultState>();
    }
    
    if (message.compare(0, kPrintCommand.size(), kPrintCommand) == 0) {
        auto it = std::next(std::begin(message), kPrintCommand.size());
        std::string text(it, std::end(message));

        std::cout << "[" << sessionName_ << "][Print] " << text << std::endl;
        return nullptr;
    }

    std::cout << "[" << sessionName_ << "] \"" << message << "\" is invalid message." << std::endl;
    return nullptr;
}

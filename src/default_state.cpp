#include "state_pattern/default_state.h"
#include "state_pattern/session_state.h"
#include <iostream>
#include <algorithm>

std::unique_ptr<MessageHandler::State> DefaultState::HandleMessage(const std::string& message) {
    const std::string kStartSessionCommand("start_session ");

    if (message.compare(0, kStartSessionCommand.size(), kStartSessionCommand) == 0) {
        auto it = std::next(std::begin(message), kStartSessionCommand.size());
        std::string sessionName(it, std::end(message));

        std::cout << "[Start Session] Session Name : " << sessionName << std::endl;
        return std::make_unique<SessionState>(std::move(sessionName));
    }
    
    std::cout << "\"" << message << "\" is invalid message." << std::endl;
    return nullptr;
}

#include "MessageHandler/DefaultState.h"
#include "MessageHandler/SessionState.h"
#include <iostream>
#include <algorithm>

namespace MessageHandler {

std::unique_ptr<State> DefaultState::HandleMessage(const std::string& message) {
    const std::string kStartSessionCommand("start_session ");
    if (message.compare(0, kStartSessionCommand.size(), kStartSessionCommand) == 0) {
        auto it = std::next(message.begin(), kStartSessionCommand.size());
        std::string sessionName(it, message.end());
        std::cout << "[Start Session] Session Name : " << sessionName << std::endl;
        return std::make_unique<SessionState>(std::move(sessionName));
    }
    std::cout << "\"" << message << "\" is invalid message." << std::endl;
    return nullptr;
}

} 

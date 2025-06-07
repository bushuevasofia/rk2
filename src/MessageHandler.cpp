#include "MessageHandler.h"
#include <iostream>
#include <string>
#include <algorithm>

// Реализация основного метода HandleMessage
void MessageHandler::HandleMessage(const std::string& message) {
    auto newState = state_->HandleMessage(message);

    if (newState) {
        state_ = std::move(newState);
    }
}

// Реализация конструктора SessionState
MessageHandler::SessionState::SessionState(std::string sessionName)
    : sessionName_(std::move(sessionName)) {
    // Можно оставить пустым — инициализация уже происходит в списке инициализации
}

// Реализация DefaultState::HandleMessage
std::unique_ptr<MessageHandler::State>
MessageHandler::DefaultState::HandleMessage(const std::string& message) {
    const std::string kStartSessionCommand("start_session ");
    if (message.compare(0, kStartSessionCommand.size(), kStartSessionCommand) == 0) {
        auto it = std::next(message.begin(), kStartSessionCommand.size());
        std::string sessionName(it, message.end());

        std::cout << "[Start Session] Session Name : " << sessionName << std::endl;
        return std::make_unique<SessionState>(std::move(sessionName));
    } else {
        std::cout << "\"" << message << "\" is invalid message." << std::endl;
        return nullptr;
    }
}

// Реализация SessionState::HandleMessage
std::unique_ptr<MessageHandler::State>
MessageHandler::SessionState::HandleMessage(const std::string& message) {
    const std::string kPrintCommand("print ");

    if (message == "end_session") {
        std::cout << "[" << sessionName_ << "][End Session]" << std::endl;
        return std::make_unique<MessageHandler::DefaultState>();
    } else if (message.compare(0, kPrintCommand.size(), kPrintCommand) == 0) {
        auto it = std::next(message.begin(), kPrintCommand.size());
        std::string text(it, message.end());

        std::cout << "[" << sessionName_ << "][Print] " << text << std::endl;
        return nullptr;
    } else {
        std::cout << "[" << sessionName_ << "] \"" << message << "\" is invalid message." << std::endl;
        return nullptr;
    }
}

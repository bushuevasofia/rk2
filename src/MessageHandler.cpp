#include "MessageHandler.h"
#include <iostream>
#include <string>
#include <algorithm>

std::unique_ptr<MessageHandler::State>
MessageHandler::DefaultState::HandleMessage(const std::string& message)
{
    const std::string kStartSessionCommand("start_session ");
    if (message.compare(0, kStartSessionCommand.size(), kStartSessionCommand) == 0)
    {
        auto it = std::next(message.begin(), kStartSessionCommand.size());
        std::string sessionName(it, message.end());

        std::cout << "[Start Session] Session Name : " << sessionName << std::endl;
        return std::make_unique<SessionState>(std::move(sessionName));
    }
    else
    {
        std::cout << "\"" << message << "\" is invalid message." << std::endl;
        return nullptr;
    }
}

std::unique_ptr<MessageHandler::State>
MessageHandler::SessionState::HandleMessage(const std::string& message)
{
    const std::string kPrintCommand("print ");

    if (message == "end_session")
    {
        std::cout << "[" << sessionName_ << "][End Session]" << std::endl;
        return std::make_unique<MessageHandler::DefaultState>();
    }
    else if (message.compare(0, kPrintCommand.size(), kPrintCommand) == 0)
    {
        auto it = std::next(message.begin(), kPrintCommand.size());
        std::string text(it, message.end());

        std::cout << "[" << sessionName_ << "][Print] " << text << std::endl;
        return nullptr;
    }
    else
    {
        std::cout << "[" << sessionName_ << "] \"" << message << "\" is invalid message." << std::endl;
        return nullptr;
    }
}

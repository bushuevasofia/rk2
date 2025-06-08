#pragma once
#include <memory>
#include <string>

class MessageHandler {
public:
    class State;  
    MessageHandler();
    void HandleMessage(const std::string& message);

private:
    std::unique_ptr<State> state_;
};

class MessageHandler::State {
public:
    virtual ~State() = default;
    virtual std::unique_ptr<State> HandleMessage(const std::string& message) = 0;
};

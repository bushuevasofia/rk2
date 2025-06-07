#pragma once
#include <memory>
#include <string>

namespace MessageHandler {

class State {
public:
    virtual ~State() = default;
    virtual std::unique_ptr<State> HandleMessage(const std::string& message) = 0;
};

} 

#pragma once
#include <memory>
#include "DefaultState.h"

namespace MessageHandler {

class MessageHandler {
public:
    MessageHandler();
    void HandleMessage(const std::string& message);
private:
    std::unique_ptr<State> state_;
};

} 

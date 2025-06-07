#pragma once
#include "State.h"

namespace MessageHandler {

class DefaultState : public State {
public:
    std::unique_ptr<State> HandleMessage(const std::string& message) override;
};

} 

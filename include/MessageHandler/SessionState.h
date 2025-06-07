#pragma once
#include "State.h"
#include <string>

namespace MessageHandler {

class SessionState : public State {
public:
    explicit SessionState(std::string sessionName);
    std::unique_ptr<State> HandleMessage(const std::string& message) override;
private:
    std::string sessionName_;
};

} 

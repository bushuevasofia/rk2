#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <string>
#include <memory>

class MessageHandler
{
public:
    void HandleMessage(const std::string& message);

private:
    class State
    {
    public:
        virtual ~State() = default;
        virtual std::unique_ptr<State> HandleMessage(const std::string& message) = 0;
    };

    class DefaultState : public State
    {
    public:
        std::unique_ptr<State> HandleMessage(const std::string& message) override;
    };

    class SessionState : public State
    {
    public:
        explicit SessionState(std::string sessionName);
        std::unique_ptr<State> HandleMessage(const std::string& message) override;

    private:
        std::string sessionName_;
    };

    std::unique_ptr<State> state_;
};

#endif // MESSAGE_HANDLER_H

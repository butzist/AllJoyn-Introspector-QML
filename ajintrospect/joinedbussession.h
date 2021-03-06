#pragma once

#include <memory>
#include <string>
#include <map>

#include "alljoynhelpers.h"
#include "iobservablebussession.h"


class JoinedBusSession : public IObservableBusSession, public ajn::SessionListener
{
public:
    JoinedBusSession(std::shared_ptr<ajn::BusAttachment> bus, const char* busName, ajn::SessionPort port, ajn::SessionOpts opts);

    void addTerminationCallback(void *reference, CallbackType callback);
    void removeTerminationCallback(void *reference);
    std::string getFullName() const;
    bool isTerminated() const override;
    std::unique_ptr<ArgumentList> invokeMethod(std::string path, std::string method, std::unique_ptr<ArgumentList> args = nullptr) override;
    std::unique_ptr<ArgumentList> createArgs() const override;
    std::string getStringProperty(std::string path, std::string property) const override;
    bool setStringProperty(std::string path, std::string property, std::string value) override;

    ajn::SessionId id() const;
    std::shared_ptr<ajn::BusAttachment> bus() const;
    std::string name() const;
    ajn::SessionPort port() const;

protected:
    void SessionLost(ajn::SessionId sessionId, SessionLostReason reason) override;

private:
    void terminateSession(std::string reason, bool isError);

    ajn::SessionId sessionId{};
    std::shared_ptr<ajn::BusAttachment> sessionBus{};
    std::string busName{};
    ajn::SessionPort sessionPort;
    std::shared_ptr<ajn::SessionListener> sessionListener{};
    std::shared_ptr<int> cleanup{};
    std::map<void*,CallbackType> callbacks{};
};

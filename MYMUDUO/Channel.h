#pragma once
#include <memory>
#include <functional>
#include "noncopyable.h"
#include "EventLoop.h"
#include "Timestamp.h"

class Channel
{
public:
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(Timestamp)>;
    Channel(EventLoop *Loop, int fd);
    ~Channel();

    void handleEvent(Timestamp receiveTime);

private:
    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;

    EventLoop* loop_;
    const int  fd_;
    int        events_;
    int        revents_; // it's the received event types of epoll or poll
    int        index_; // used by Poller.

    std::weak_ptr<void> tie_;
    bool tied_;

    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;
};
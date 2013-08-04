#ifndef TIMER_H
#define TIMER_H

#include "SignalSlot.h"

class Timer
{
public:
    enum { SingleShot = 0x1 };

    Timer();
    Timer(int interval, int flags = 0);
    ~Timer();

    void restart(int interval, int flags = 0);
    void stop();

    Signal<std::function<void(Timer*)> >& timeout() { return signalTimeout; }

private:
    void timerFired(int id);

private:
    int timerId;
    Signal<std::function<void(Timer*)> > signalTimeout;
};

#endif

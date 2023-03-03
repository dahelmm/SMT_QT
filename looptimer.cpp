#include <QDebug>

#include "looptimer.h"

LoopTimer::~LoopTimer()
{
    stop();
}

void LoopTimer::setup(std::function<void (int channel)> func)
{
    callback = func;
    running = true;
    start();
}

void LoopTimer::stop()
{
    running = false;
    quit();
}

void LoopTimer::run()
{
    setPriority(TimeCriticalPriority);
    while(running){
        action();
    }
}

void LoopTimer::action()
{
    try {
        callback(m_channel);
    } catch (std::bad_typeid &err) {
        qWarning()<<tr("LoopTimer: callback error %1").arg(err.what());
    }
}

void LoopTimer::setChannel(int channel)
{
    m_channel = channel;
}

void LoopTimer::setCycledMode(bool mode)
{
    cycled = mode;
}

bool LoopTimer::cycledMode() const
{
    return cycled;
}

bool LoopTimer::isRun()
{
    return running;
}

void LoopTimer::startRunning()
{
    running = true;
}

void LoopTimer::stopRunning()
{
    running = false;
}

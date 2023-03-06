#include "transmitter.h"

Transmitter::Transmitter(ElcusHelper *elcus, QObject *parent) :
    QObject(parent),
    m_udp(nullptr),
    m_elcus(elcus),
    m_running(false)
{

}

Transmitter::~Transmitter()
{

}

void Transmitter::run()
{
    exec();
    while(isRunning()){
      QThread::msleep(50);
      qApp->processEvents();
    }
    emit finished();
}

void Transmitter::stop()
{

}

void Transmitter::start()
{

}

void Transmitter::exec()
{

}

void Transmitter::quit()
{

}

bool Transmitter::isRunning()
{
    return m_running;
}

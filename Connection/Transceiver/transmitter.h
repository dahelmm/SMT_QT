#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <QObject>
#include <QThread>
#include <QApplication>


#include "Connection/Transceiver/Udp/udp.h"
#include "Elcus/elcushelper.h"

class Transmitter : public QObject
{
        Q_OBJECT
    public:
        explicit Transmitter(ElcusHelper *elcus = nullptr, QObject *parent = nullptr);
        ~Transmitter();

        void run();
        void stop();
        void start();
        void exec();
        void quit();
        bool isRunning();


    signals:
        void started();
        void finished();
        void dataReceived(int channel, int address, int value, int state);

    private:
        QScopedPointer<Udp> m_udp;
        ElcusHelper *m_elcus;
        bool m_running;
};

#endif // TRANSMITTER_H

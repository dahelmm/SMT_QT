#ifndef LOOPTIMER_H
#define LOOPTIMER_H

#include <QThread>

class LoopTimer : public QThread
{
        Q_OBJECT
    public:
        ~LoopTimer();

        void setup(std::function<void(int channel)> func);
        void stop();
        void run() override;
        void action();
        void setChannel(int channel);
        void setCycledMode(bool mode);
        bool cycledMode() const;
        bool isRun();
        void startRunning();
        void stopRunning();

    signals:
        void groupSend(int numberElement, int value, int channel);
        void fileChanged(const QString &nameFile);

    private:
        bool running = false;
        std::function<void(int)> callback;
        int m_channel;
        bool cycled = false;
};

#endif // LOOPTIMER_H

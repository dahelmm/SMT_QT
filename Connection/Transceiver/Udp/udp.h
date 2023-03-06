#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>

#define ARINC429_NET_HEADER "NETARINC429 2.0"

class Udp : public QObject
{
        Q_OBJECT

    public:
        explicit Udp(QString host = "127.0.0.1", int port = 3000);
        ~Udp();

        void setHostPort(const QString &host, const int port);
        void connectToHost();
        void writeData(QByteArray data);
        void setCallbackForReceive(std::function<void(int, char*, size_t)> function);

        const QString &getHost();
        int getPort() const;

    private:
        void readMessage(int channel, char *data, size_t size);

    private slots:
        void readData();


    private:
        QUdpSocket *m_socket;
        std::function <void(int, char*, size_t)> callback;

        QString m_udpHost;
        int m_udpPort;
};

#endif // UDP_H

#include "udp.h"

Udp::Udp(QString host, int port) :
    m_udpHost(host),
    m_udpPort(port)
{
    m_socket = new QUdpSocket(this);
    connect(m_socket, &QUdpSocket::readyRead, this, &Udp::readData);
}

Udp::~Udp()
{
    m_socket->close();
}

void Udp::setHostPort(const QString &host, const int port)
{
    if(host.isEmpty())
        return;
    if(m_socket->state() == QAbstractSocket::BoundState)
        m_socket->leaveMulticastGroup(QHostAddress(m_udpHost));
    m_socket->close();
    m_udpHost = host;
    m_udpPort = port;
    m_socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    m_socket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 1);
    m_socket->setSocketOption(QAbstractSocket::MulticastTtlOption, 255);
    bool error = m_socket->bind(QHostAddress(QHostAddress::AnyIPv4), m_udpPort,
                                QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    if(!error)
        qWarning() << tr("Bind %1 %2 failed").arg(m_udpHost).arg(m_udpPort);
    if(m_socket->state() == QAbstractSocket::BoundState)
        m_socket->joinMulticastGroup(QHostAddress(m_udpHost));
}

void Udp::connectToHost()
{
    m_socket->connectToHost(m_udpHost, m_udpPort);
}

void Udp::writeData(QByteArray data)
{
    if(data.isEmpty())
        return;
    m_socket->writeDatagram(data, QHostAddress(m_udpHost), m_udpPort);
}

void Udp::setCallbackForReceive(std::function<void (int, char *, size_t)> function)
{
    callback = function;
}

const QString &Udp::getHost()
{
    return m_udpHost;

}

int Udp::getPort() const
{
    return m_udpPort;
}

void Udp::readMessage(int channel, char *data, size_t size)
{
    try {
        callback(channel, data, size);
    } catch (std::bad_typeid &err) {
        qWarning() << tr("Udp: callback function error: %1").arg(err.what());
    }
}

void Udp::readData()
{
    while(m_socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());
        qint64 error = m_socket->readDatagram(datagram.data(), datagram.size());
        if(error == -1 && m_socket->error() != QAbstractSocket::UnknownSocketError)
        {
            qWarning() << tr("Udp: read datagram error: %1, %2, %3").arg(error).arg(m_socket->error()).arg(m_socket->errorString());
        }
        if(datagram.left(15) == ARINC429_NET_HEADER)
            readMessage(datagram[16],(char*)datagram.mid(20).data(), datagram.mid(20).size());
    }
}

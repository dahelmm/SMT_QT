#ifndef CONNECTION_H
#define CONNECTION_H

#include "Connection/Udp/udp.h"
#include <QObject>

class Connection
{
    public:
        Connection();

    private:
        Udp *m_udp;
};

#endif // CONNECTION_H

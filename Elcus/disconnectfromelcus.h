#ifndef DISCONNECTFROMELCUS_H
#define DISCONNECTFROMELCUS_H

#include <QDialog>
#include <QVector>

#include "elcushelper.h"

namespace Ui {
    class DisconnectFromElcus;
}

class DisconnectFromElcus : public QDialog
{
        Q_OBJECT

    public:
        explicit DisconnectFromElcus(QWidget *parent = nullptr);
        ~DisconnectFromElcus();
        void setVectorConnections(QVector<ElcusHelper*> *vector);
    signals:
        void disconnectedElcus(int currentElcusDelete);

    private slots:
        void on_bttnDisconnectElcus_clicked();

    private:
        Ui::DisconnectFromElcus *ui;

        QVector<ElcusHelper*> *m_tempConnectionsWithElcus;
};

#endif // DISCONNECTFROMELCUS_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Elcus/elcushelper.h"
#include "Elcus/connectnewelcus.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void connectionSuccessful(HANDLE hDevice, USHORT serialNumber);

        void on_actionConnectToElcus_triggered();
        void on_actionStartLog2Sender_triggered();
        void on_bttnAddConnection_clicked();

        void on_cmbBoxConnections_currentIndexChanged(int index);

        void on_bttnStartConnections_clicked();

    private:
        Ui::MainWindow *ui;

        QList<ElcusHelper*> m_elcusConnections;
        ///текущее подключение
        ConnectNewElcus *m_connectingToElcus;

};
#endif // MAINWINDOW_H

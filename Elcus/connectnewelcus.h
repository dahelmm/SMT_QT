#ifndef CONNECTNEWELCUS_H
#define CONNECTNEWELCUS_H

#include <QDialog>

#include <windows.h>
#include <winioctl.h>
#include <setupapi.h>

namespace Ui {
    class ConnectNewElcus;
}

class ConnectNewElcus : public QDialog
{
        Q_OBJECT

    public:
        explicit ConnectNewElcus(QWidget *parent = nullptr);
        ~ConnectNewElcus();

    signals:
        void connectNewElcusTrue(HANDLE, USHORT);
        void closeWindow();

    private slots:
        void on_bttnConnect_clicked();
        void on_bttnCancel_clicked();

    private:
        Ui::ConnectNewElcus *ui;
};

#endif // CONNECTNEWELCUS_H

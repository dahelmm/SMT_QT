#include <QMessageBox>

#include "connectnewelcus.h"
#include "ui_connectnewelcus.h"

extern HANDLE OpenDeviceBySN(USHORT SerialNumber, PDWORD pError );

ConnectNewElcus::ConnectNewElcus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectNewElcus)
{
    ui->setupUi(this);
}

ConnectNewElcus::~ConnectNewElcus()
{
    delete ui;
}

void ConnectNewElcus::on_bttnConnect_clicked()
{
    //подключение платы, проверка серийного номера и отправка сигнала об успешном подключении
    DWORD error;
    USHORT serialNumber = ui->lineEditSerialNumberNewElcus->text().toUInt();
    HANDLE hDevice = OpenDeviceBySN(serialNumber, &error);
    if(hDevice == INVALID_HANDLE_VALUE)
    {
        QMessageBox::critical(this, tr("Ошибка"), tr("Неверный серийный номер, либо плата не подключена, попробуйте снова"));
        return;
    }
    emit connectNewElcusTrue(hDevice, serialNumber);
    ui->lineEditSerialNumberNewElcus->clear();
}

void ConnectNewElcus::on_bttnCancel_clicked()
{
    this->close();
}

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectionSuccessful(HANDLE hDevice, USHORT serialNumber)
{
    foreach (auto *elcus, m_elcusConnections) {
        if(elcus->getSerialNumber() == serialNumber){
            QMessageBox::critical(this, tr("Ошибка подключения"), tr("Плата с таким серийным номером уже имеется, подключите другую или используйте имеющуюся"));
            return;
        }
    }
    USHORT tempBufferOutput[5];
    ElcusHelper *newConnect = new ElcusHelper(this);
    m_elcusConnections.append(newConnect);

    newConnect->setHDevice(hDevice);
    USHORT id = newConnect->readRID();
    newConnect->setSerialNumber(serialNumber);
    newConnect->getState(tempBufferOutput);

    if ((tempBufferOutput[0]!=0x0BCC)||
            (tempBufferOutput[1]!=0xDC9D)||
            (tempBufferOutput[3]!=0))
    {
        QMessageBox::critical(this,"Ошибка перехода в режим НАСТРОЙКА",
                              "RESET:\n ОШИБКИ:\n "
                              "МР = " + QString::number(tempBufferOutput[0]) + "\n" +
                              "РМ = " + QString::number(tempBufferOutput[1]) + "\n" +
                              "ВСК = " + QString::number(tempBufferOutput[3]));
        m_elcusConnections.removeOne(newConnect);
        newConnect->deleteLater();
        return;
    }
    int flagReset = 0;
    newConnect->writeRV(flagReset);
    newConnect->writeRM(0x6000);//0110 0000 0000 0000
    switch (id) {
        case typeElcus::PCI429_4_3:
            newConnect->setTypeElcus(typeElcus::PCI429_4_3);
            newConnect->setNumberInputChannels(16);
            newConnect->setNumberOutputChannels(16);
            break;
        case typeElcus::PCI429_4_2:
            newConnect->setTypeElcus(typeElcus::PCI429_4_2);
            newConnect->setNumberInputChannels(16);
            newConnect->setNumberOutputChannels(8);
            break;
        case typeElcus::PCI429_4_1:
            newConnect->setTypeElcus(typeElcus::PCI429_4_1);
            newConnect->setNumberInputChannels(8);
            newConnect->setNumberOutputChannels(8);
            break;
        default:
            break;
    }
    int codeKCR = 0x80; //командное слово режима
    newConnect->setKSR(codeKCR);
    m_connectingToElcus->close();
    m_connectingToElcus->deleteLater();
    m_connectingToElcus = nullptr;
}

void MainWindow::on_actionConnectToElcus_triggered()
{
    m_connectingToElcus = new ConnectNewElcus(this);
    connect(m_connectingToElcus, &ConnectNewElcus::connectNewElcusTrue, this, &MainWindow::connectionSuccessful);
    m_connectingToElcus->exec();
}


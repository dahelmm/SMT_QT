#include "disconnectfromelcus.h"
#include "ui_disconnectfromelcus.h"

DisconnectFromElcus::DisconnectFromElcus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisconnectFromElcus)
{
    ui->setupUi(this);
}

DisconnectFromElcus::~DisconnectFromElcus()
{
    delete ui;
}

void DisconnectFromElcus::setVectorConnections(QVector<ElcusHelper *> * vector)
{
    m_tempConnectionsWithElcus = vector;
    if(!m_tempConnectionsWithElcus->isEmpty())
    {
        for(int i = 0, it = m_tempConnectionsWithElcus->size(); i != it; ++i)
        {
            ElcusHelper *elcus = m_tempConnectionsWithElcus->value(i);
            ui->comboBoxChooseElcus->insertItem(ui->comboBoxChooseElcus->count(), tr("%1").arg(elcus->getSerialNumber()));
        }
    }
}

void DisconnectFromElcus::on_bttnDisconnectElcus_clicked()
{
    int choosedElcus = ui->comboBoxChooseElcus->currentIndex();
    ElcusHelper *elcus = m_tempConnectionsWithElcus->value(choosedElcus);
    if(!elcus)
        return;
    elcus->deleteLater();
    ui->comboBoxChooseElcus->removeItem(choosedElcus);
    m_tempConnectionsWithElcus->remove(choosedElcus);
    emit disconnectedElcus(choosedElcus);
    if(m_tempConnectionsWithElcus->isEmpty())
        this->close();
}

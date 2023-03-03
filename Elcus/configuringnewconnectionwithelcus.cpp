#include "configuringnewconnectionwithelcus.h"
#include "ui_configuringnewconnectionwithelcus.h"

ConfiguringNewConnectionWithElcus::ConfiguringNewConnectionWithElcus(ElcusHelper * elcus, QWidget * parent):
    QDialog(parent),
    ui(new Ui::ConfiguringNewConnectionWithElcus),
    m_elcus(elcus)
{
    ui->setupUi(this);

    /* В зависимости от типа подключаемого модуля, выбирается, сколько активных и настраиваемых
     * каналов будет в плате. */
    switch(m_elcus->getTypeElcus()){
        case typeElcus::PCI429_4_1:
            ui->l_ch_9->setVisible(false);
            ui->l_ch_10->setVisible(false);
            ui->l_ch_11->setVisible(false);
            ui->l_ch_12->setVisible(false);
            ui->l_ch_13->setVisible(false);
            ui->l_ch_14->setVisible(false);
            ui->l_ch_15->setVisible(false);
            ui->l_ch_16->setVisible(false);
            ui->l_ch_25->setVisible(false);
            ui->l_ch_26->setVisible(false);
            ui->l_ch_27->setVisible(false);
            ui->l_ch_28->setVisible(false);
            ui->l_ch_29->setVisible(false);
            ui->l_ch_30->setVisible(false);
            ui->l_ch_31->setVisible(false);
            ui->l_ch_32->setVisible(false);
            ui->cmbB_freeq_i_ch_9->setVisible(false);
            ui->cmbB_freeq_i_ch_10->setVisible(false);
            ui->cmbB_freeq_i_ch_11->setVisible(false);
            ui->cmbB_freeq_i_ch_12->setVisible(false);
            ui->cmbB_freeq_i_ch_13->setVisible(false);
            ui->cmbB_freeq_i_ch_14->setVisible(false);
            ui->cmbB_freeq_i_ch_15->setVisible(false);
            ui->cmbB_freeq_i_ch_16->setVisible(false);
            ui->cmbB_freeq_o_ch_9->setVisible(false);
            ui->cmbB_freeq_o_ch_10->setVisible(false);
            ui->cmbB_freeq_o_ch_11->setVisible(false);
            ui->cmbB_freeq_o_ch_12->setVisible(false);
            ui->cmbB_freeq_o_ch_13->setVisible(false);
            ui->cmbB_freeq_o_ch_14->setVisible(false);
            ui->cmbB_freeq_o_ch_15->setVisible(false);
            ui->cmbB_freeq_o_ch_16->setVisible(false);
            break;
        case typeElcus::PCI429_4_2:
            ui->l_ch_9->setVisible(false);
            ui->l_ch_10->setVisible(false);
            ui->l_ch_11->setVisible(false);
            ui->l_ch_12->setVisible(false);
            ui->l_ch_13->setVisible(false);
            ui->l_ch_14->setVisible(false);
            ui->l_ch_15->setVisible(false);
            ui->l_ch_16->setVisible(false);
            ui->cmbB_freeq_o_ch_9->setVisible(false);
            ui->cmbB_freeq_o_ch_10->setVisible(false);
            ui->cmbB_freeq_o_ch_11->setVisible(false);
            ui->cmbB_freeq_o_ch_12->setVisible(false);
            ui->cmbB_freeq_o_ch_13->setVisible(false);
            ui->cmbB_freeq_o_ch_14->setVisible(false);
            ui->cmbB_freeq_o_ch_15->setVisible(false);
            ui->cmbB_freeq_o_ch_16->setVisible(false);
            break;
        case typeElcus::PCI429_4_3:
            break;
    }
}

ConfiguringNewConnectionWithElcus::~ConfiguringNewConnectionWithElcus()
{
    delete ui;
}

void ConfiguringNewConnectionWithElcus::on_pB_applySettings_clicked()
{
    QMap<int,QComboBox*> cmbm_boxesInputs;
    QMap<int,QComboBox*> cmbm_boxesOutputs;

    USHORT buffFreeq[0x40];

    int i = 0;

    cmbm_boxesInputs[0] = ui->cmbB_freeq_i_ch_1;
    cmbm_boxesInputs[1] = ui->cmbB_freeq_i_ch_2;
    cmbm_boxesInputs[2] = ui->cmbB_freeq_i_ch_3;
    cmbm_boxesInputs[3] = ui->cmbB_freeq_i_ch_4;
    cmbm_boxesInputs[4] = ui->cmbB_freeq_i_ch_5;
    cmbm_boxesInputs[5] = ui->cmbB_freeq_i_ch_6;
    cmbm_boxesInputs[6] = ui->cmbB_freeq_i_ch_7;
    cmbm_boxesInputs[7] = ui->cmbB_freeq_i_ch_8;
    cmbm_boxesInputs[8] = ui->cmbB_freeq_i_ch_9;
    cmbm_boxesInputs[9] = ui->cmbB_freeq_i_ch_10;
    cmbm_boxesInputs[10] = ui->cmbB_freeq_i_ch_11;
    cmbm_boxesInputs[11] = ui->cmbB_freeq_i_ch_12;
    cmbm_boxesInputs[12] = ui->cmbB_freeq_i_ch_13;
    cmbm_boxesInputs[13] = ui->cmbB_freeq_i_ch_14;
    cmbm_boxesInputs[14] = ui->cmbB_freeq_i_ch_15;
    cmbm_boxesInputs[15] = ui->cmbB_freeq_i_ch_16;

    cmbm_boxesOutputs[0] = ui->cmbB_freeq_o_ch_1;
    cmbm_boxesOutputs[1] = ui->cmbB_freeq_o_ch_2;
    cmbm_boxesOutputs[2] = ui->cmbB_freeq_o_ch_3;
    cmbm_boxesOutputs[3] = ui->cmbB_freeq_o_ch_4;
    cmbm_boxesOutputs[4] = ui->cmbB_freeq_o_ch_5;
    cmbm_boxesOutputs[5] = ui->cmbB_freeq_o_ch_6;
    cmbm_boxesOutputs[6] = ui->cmbB_freeq_o_ch_7;
    cmbm_boxesOutputs[7] = ui->cmbB_freeq_o_ch_8;
    cmbm_boxesOutputs[8] = ui->cmbB_freeq_o_ch_9;
    cmbm_boxesOutputs[9] = ui->cmbB_freeq_o_ch_10;
    cmbm_boxesOutputs[10] = ui->cmbB_freeq_o_ch_11;
    cmbm_boxesOutputs[11] = ui->cmbB_freeq_o_ch_12;
    cmbm_boxesOutputs[12] = ui->cmbB_freeq_o_ch_13;
    cmbm_boxesOutputs[13] = ui->cmbB_freeq_o_ch_14;
    cmbm_boxesOutputs[14] = ui->cmbB_freeq_o_ch_15;
    cmbm_boxesOutputs[15] = ui->cmbB_freeq_o_ch_16;

    foreach(auto*item, cmbm_boxesInputs)
    {
        buffFreeq[i] = item->currentIndex();
        i++;
    }
    foreach(auto*item, cmbm_boxesOutputs)
    {
        buffFreeq[i] = item->currentIndex();
        i++;
    }
    m_elcus->setFreeqChannels(buffFreeq);
    m_elcus->setKCI();
    emit settingsApplied();
    this->close();
}

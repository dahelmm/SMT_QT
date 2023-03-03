#ifndef CONFIGURINGNEWCONNECTIONWITHELCUS_H
#define CONFIGURINGNEWCONNECTIONWITHELCUS_H

#include <QDialog>

#include "elcushelper.h"

namespace Ui {
    class ConfiguringNewConnectionWithElcus;
}

class ConfiguringNewConnectionWithElcus : public QDialog
{
        Q_OBJECT

    public:
        explicit ConfiguringNewConnectionWithElcus(ElcusHelper *elcus, QWidget *parent = nullptr);
        ~ConfiguringNewConnectionWithElcus();

    signals:
        void settingsApplied();

    private slots:
        void on_pB_applySettings_clicked();

    private:
        Ui::ConfiguringNewConnectionWithElcus *ui;
        ElcusHelper *m_elcus;
};

#endif // CONFIGURINGNEWCONNECTIONWITHELCUS_H

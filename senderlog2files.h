#ifndef SENDERLOG2FILES_H
#define SENDERLOG2FILES_H

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSpinBox>
#include <QElapsedTimer>
#include <QMap>
#include <QCheckBox>


#include "Elcus/elcushelper.h"
#include "looptimer.h"


struct Word {
    int address;
    int value;
    int state;
};

struct WordsGroup
{
    QList<Word*> words;
    QElapsedTimer sendingTimer;
    int sendingTimeout;
    bool sended;
};

struct File {
    QList<WordsGroup*> groups;
    QString nameFile;
};

namespace Ui {
    class SenderLog2Files;
}

class SenderLog2Files : public QWidget
{
        Q_OBJECT

    public:
        explicit SenderLog2Files(ElcusHelper *elcus, QWidget *parent = nullptr);
        ~SenderLog2Files();

    private slots:
        void startParser();
        void usingParsedData();
        void changeProgressBar(int numberElement, int value, int channel);
        void startSending(int channel);
        void clearAllData();
        void closeEvent(QCloseEvent *event) override;

        void on_bttnStartSending_clicked();
        void on_bttnStopSending_clicked();

    private:
        Ui::SenderLog2Files *ui;

        QList<QPushButton*> m_bttns;
        QList<QProgressBar*> m_progresses;
        QList<QSpinBox*> m_spinBoxes;
        QList<QCheckBox*> m_checkBoxesCycled;

        QList<QList<File*>> m_data;

        ElcusHelper *m_elcus;

        QList<QSharedPointer<LoopTimer>> m_timers;
        QList<int> m_channels;
//        QList<bool> signStopChannels;
};

#endif // SENDERLOG2FILES_H

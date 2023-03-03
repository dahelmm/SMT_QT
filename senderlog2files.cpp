#include <QFileDialog>
#include <QMessageBox>

#include "looptimer.h"
#include "qdebug.h"
#include "senderlog2files.h"
#include "ui_senderlog2files.h"

SenderLog2Files::SenderLog2Files(ElcusHelper *elcus, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SenderLog2Files),
    m_elcus(elcus)
{
    ui->setupUi(this);

    m_checkBoxesCycled.append(ui->checkBoxCh1);
    m_checkBoxesCycled.append(ui->checkBoxCh2);
    m_checkBoxesCycled.append(ui->checkBoxCh3);
    m_checkBoxesCycled.append(ui->checkBoxCh4);
    m_checkBoxesCycled.append(ui->checkBoxCh5);
    foreach(auto *check, m_checkBoxesCycled){
        connect(check, &QCheckBox::stateChanged, [=](int value){
            int numberCheckBox = m_checkBoxesCycled.indexOf(check);
#ifdef DEBUGGING_OUTPUT
            qDebug()<<numberCheckBox;
#endif
            if(value == Qt::Unchecked)
                m_timers[numberCheckBox]->setCycledMode(false);
            else if(value == Qt::Checked)
                m_timers[numberCheckBox]->setCycledMode(true);
        });
        check->setEnabled(false);
    }

    m_spinBoxes.append(ui->spinBoxCh1);
    m_spinBoxes.append(ui->spinBoxCh2);
    m_spinBoxes.append(ui->spinBoxCh3);
    m_spinBoxes.append(ui->spinBoxCh4);
    m_spinBoxes.append(ui->spinBoxCh5);
    foreach (auto *spin, m_spinBoxes) {
        m_channels.append(spin->value());
        connect(spin, QOverload<int>::of(&QSpinBox::valueChanged), [=](int value){
            int number = m_spinBoxes.indexOf(spin);
            m_channels[number] = value;
        });
    }

    m_progresses.append(ui->progressBar1);
    m_progresses.append(ui->progressBar2);
    m_progresses.append(ui->progressBar3);
    m_progresses.append(ui->progressBar4);
    m_progresses.append(ui->progressBar5);

    m_bttns.append(ui->bttnChooseFiles1);
    m_bttns.append(ui->bttnChooseFiles2);
    m_bttns.append(ui->bttnChooseFiles3);
    m_bttns.append(ui->bttnChooseFiles4);
    m_bttns.append(ui->bttnChooseFiles5);

    foreach(auto *bttn, m_bttns){
        connect(bttn, &QPushButton::clicked, this, &SenderLog2Files::startParser);
        bttn->setEnabled(false);
    }
    ui->bttnChooseFiles1->setEnabled(true);

    ui->bttnStartSending->setEnabled(true);
    ui->bttnStopSending->setEnabled(false);

}

SenderLog2Files::~SenderLog2Files()
{
    delete ui;
}

void SenderLog2Files::startParser()
{

    QPushButton *senderBttn = qobject_cast<QPushButton*>(sender());
    Q_ASSERT(senderBttn);
    int numberBttn = m_bttns.indexOf(senderBttn);

    m_data.removeAt(numberBttn);

    QStringList filePath = QFileDialog::getOpenFileNames(this, tr("Выберите файлы"), QString(), "*.log2");
    if(filePath.isEmpty())
        return;

    QFile outFile("./out.txt");
    outFile.remove();
    outFile.open(QIODevice::Append);

    foreach (QString oneFile, filePath) {
        QFile file(oneFile);
        if(file.open(QIODevice::ReadOnly)){
            QFileInfo fileInfo(oneFile);
            QByteArray currentFileName = tr("file: %1 \n").arg(fileInfo.fileName()).toUtf8();
            outFile.write(currentFileName.data());
            while(!file.atEnd()){
                QByteArray array;
                array = file.read(4);
                while(!array.isEmpty()){
                    array = file.read(4);
                    array = file.read(2);
                    std::reverse(array.begin(), array.end());
                    unsigned int time = array.toHex().toUInt(nullptr, 16);
                    array.clear();
                    array.append(tr("time: %1").arg(time, 4, 16, QChar('0')).toUtf8());
                    outFile.write(array + "\n");
                    array.clear();
                    array = file.read(2);
                    std::reverse(array.begin(), array.end());
                    for(int i = 0, it = array.toHex().toLongLong(nullptr, 16) - 10; i <= it; i+=4){
                        array = file.read(4);
                        std::reverse(array.begin(), array.end());
                        unsigned int value = array.toHex().toUInt(nullptr, 16);
                        array.clear();
                        array.append(tr("%1").arg(value, 8, 16, QChar('0')).toUtf8());
                        outFile.write(array + "\n");
                    }
                    outFile.write("\n");
                }
            }
        }
        file.close();
    }
    outFile.close();

    usingParsedData();

    int countGroups = 0;
    foreach(auto *file, m_data[numberBttn]){
        countGroups += file->groups.count();
    }
    m_progresses[numberBttn]->setMaximum(countGroups);
    m_progresses[numberBttn]->setValue(0);
    if(numberBttn+1 < m_bttns.count()){
        QPushButton *bttn = m_bttns.at(++numberBttn);
        bttn->setEnabled(true);
    }

}

void SenderLog2Files::usingParsedData()
{
    QFile parsedDataFile("./out.txt");
    parsedDataFile.open(QIODevice::ReadOnly);
    QList<File*> currentList;
    QString line;
    while (!parsedDataFile.atEnd()) {
        line = parsedDataFile.readLine();
        if(line.simplified().isEmpty())
            continue;
        if(line.contains("file: ")){
            File *newFile = new File;
            newFile->nameFile = QByteArray(line.toUtf8().remove(0,6).simplified());
            currentList.append(newFile);
            continue;
        }
        else if(line.contains("time: ")){
            WordsGroup *group = new WordsGroup;
            group->sended = false;
            group->sendingTimeout = QByteArray(line.toUtf8().remove(0,6).simplified()).toInt(nullptr, 16);
            currentList.last()->groups.append(group);
        }
        else {
            QByteArray array(line.toUtf8().simplified());
            unsigned long value = array.toULong(nullptr, 16);
            Word *word = new Word;
            word->address = value & 0xff;
            word->value = (value >> 8) & 0x1fffff;
            word->state = (value >> 29) & 0x3;
            currentList.last()->groups.last()->words.append(word);
        }
    }
    m_data.append(currentList);
}

void SenderLog2Files::changeProgressBar(int numberElement, int value, int channel)
{
    m_progresses[numberElement]->setValue(value);
    if(m_progresses[numberElement]->value() == m_progresses[numberElement]->maximum() && m_timers[numberElement]->cycledMode()){
        foreach (auto *file, m_data[numberElement]) {
            foreach (auto *group, file->groups) {
                group->sended = false;
            }
        }
    }
    else if(m_progresses[numberElement]->value() == m_progresses[numberElement]->maximum() && !m_timers[numberElement]->cycledMode()){
        m_timers[numberElement]->stop();
        bool allTimersIsStoped = true;
        foreach (auto timer, m_timers) {
            if(timer->isRun()){
                allTimersIsStoped = false;
                break;
            }
        }
        if(allTimersIsStoped){
            clearAllData();
            QMessageBox::information(this, tr("Готово"), tr("Все логи переданы"));
            ui->bttnStartSending->setEnabled(true);
            ui->bttnStopSending->setEnabled(false);

        }
    }
}

void SenderLog2Files::startSending(int channel)
{
    int numberEnabled = 0;
    foreach(auto *check, m_checkBoxesCycled){
        check->setEnabled(true);
        numberEnabled++;
        if(numberEnabled == m_data.count())
            break;
    }

    int numberList = m_channels.indexOf(channel);
    QList<File*> m_files = m_data[numberList];
    LoopTimer *timer = m_timers[numberList].data();
    foreach (auto *file, m_files) {
        int counterGroupsInFile = 0;

        foreach (auto *group, file->groups) {
            group->sendingTimer.restart();
        }
        while(counterGroupsInFile != file->groups.count() && timer->isRun()){
            foreach (auto *group, file->groups) {
                if(!group->sended &&
                        group->sendingTimer.elapsed() > group->sendingTimeout){
                    foreach (auto *word, group->words) {
                        m_elcus->wtiteDataToMemory(word->address,
                                                   word->value,
                                                   word->state);
#ifdef DEBUGGING_OUTPUT
                        qDebug()<< tr("%1").arg(word->address, 3, 8);
                        qDebug()<< tr("%1").arg(word->value, 21, 2, QChar('0'));
#endif
                    }
                    m_elcus->writeBRV(channel);
                    group->sended = true;
                    counterGroupsInFile++;
                    emit timer->groupSend(numberList, counterGroupsInFile, channel);
                }
            }
        }
    }
}

void SenderLog2Files::clearAllData()
{
    foreach (auto files, m_data) {
        foreach (auto *file, files) {
            foreach (auto *group, file->groups) {
                qDeleteAll(group->words);
            }
            qDeleteAll(file->groups);
        }
        qDeleteAll(files);
    }
    m_data.clear();
}

void SenderLog2Files::closeEvent(QCloseEvent *event)
{
    foreach (auto timer, m_timers) {
        timer->stop();
    }
    clearAllData();
}

void SenderLog2Files::on_bttnStartSending_clicked()
{
    int numberTimer = 0;
    if(m_data.isEmpty()){
        usingParsedData();
        foreach (auto *pb, m_progresses) {
            pb->setValue(0);
        }
    }
    if(m_timers.count()){
        m_timers.clear();
    }
    foreach (auto files, m_data){
        foreach (auto curFile, files) {
            foreach(auto *group, curFile->groups){
                group->sendingTimer.restart();
            }
        }

        m_timers.append(QSharedPointer<LoopTimer>(new LoopTimer));
        LoopTimer *loop = m_timers.last().data();

        loop->setChannel(m_channels[numberTimer]);
        loop->setup(std::bind(&SenderLog2Files::startSending, this, std::placeholders::_1));
        connect(loop, &LoopTimer::groupSend, this, &SenderLog2Files::changeProgressBar, Qt::QueuedConnection);
        numberTimer++;

    }
    ui->bttnStartSending->setEnabled(false);
    ui->bttnStopSending->setEnabled(true);
}


void SenderLog2Files::on_bttnStopSending_clicked()
{
    foreach (auto timer, m_timers) {
        timer->stop();
    }
    ui->bttnStartSending->setEnabled(true);
    ui->bttnStopSending->setEnabled(false);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QStringBuilder>
#include <QSignalSpy>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spyPushButton_ = new QSignalSpy(ui->pushButton, SIGNAL(clicked()));
    spyRadioButton_ = new QSignalSpy(ui->radioButton, SIGNAL(clicked(bool)));
    spyLineEdit_ = new QSignalSpy(ui->lineEdit, SIGNAL(textEdited(QString)));
    spySpinBox_ = new QSignalSpy(ui->spinBox, SIGNAL(valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete spyPushButton_;
    delete spyRadioButton_;
    delete spyLineEdit_;
    delete spySpinBox_;

    delete ui;
}

void MainWindow::on_btnLog_clicked()
{
    QString log;

    log += "PushButton count calls: " % QString::number(spyPushButton_->count()) % QChar::LineSeparator;

    log += QChar::LineSeparator;
    log += "RadioButton count calls: " % QString::number(spyRadioButton_->count()) % QChar::LineSeparator;
    for (auto it = spyRadioButton_->cbegin(); it != spyRadioButton_->cend(); ++it) {
        QList<QVariant> arg = *it;
        log += "    RadioButton call with arg bool - " % arg.first().toString() % QChar::LineSeparator;
    }

    log += QChar::LineSeparator;
    log += "SpinBox count calls: " % QString::number(spySpinBox_->count()) % QChar::LineSeparator;
    for (auto it = spySpinBox_->cbegin(); it != spySpinBox_->cend(); ++it) {
        QList<QVariant> arg = *it;
        log += "    SpinBox call with arg int - " % arg.first().toString() % QChar::LineSeparator;
    }

    log += QChar::LineSeparator;
    log += "LineEdit count calls: " % QString::number(spyLineEdit_->count()) % QChar::LineSeparator;
    for (auto it = spyLineEdit_->cbegin(); it != spyLineEdit_->cend(); ++it) {
        QList<QVariant> arg = *it;
        log += "    LineEdit call with arg string - " % arg.first().toString() % QChar::LineSeparator;
    }

    ui->txtLog->setText(log);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSignalSpy;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnLog_clicked();

private:

    Ui::MainWindow* ui;

    QSignalSpy* spyPushButton_;
    QSignalSpy* spyRadioButton_;
    QSignalSpy* spySpinBox_;
    QSignalSpy* spyLineEdit_;
};

#endif // MAINWINDOW_H

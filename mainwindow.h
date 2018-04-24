#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSignalSpy;

namespace Ui {
class MainWindow;
}

struct CustomStruct {
    int d;
    int e;
};

Q_DECLARE_METATYPE(CustomStruct)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

signals:

    void changeValue(CustomStruct value);

private slots:

    void on_btnLog_clicked();

    void on_spinBox_valueChanged(int value);

private:

    Ui::MainWindow* ui;

    QSignalSpy* spyPushButton_;
    QSignalSpy* spyRadioButton_;
    QSignalSpy* spySpinBox_;
    QSignalSpy* spyLineEdit_;
    QSignalSpy* spyCustom_;
};

#endif // MAINWINDOW_H

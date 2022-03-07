#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringListModel* qslm = nullptr;

private slots:
    void on_pushButton_Line_clicked();

    void on_pushButton_Rectangle_clicked();

private:
    Ui::MainWindow *ui;
    GLWidget *glw;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
//#include "treemodel.h"
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Line_clicked();

    void on_pushButton_Rectangle_clicked();

    void on_pushButton_Triangle_clicked();

private:
    Ui::MainWindow *ui;
    GLWidget *glw;
    QStandardItemModel *qsim;
    //treeModel *tm;

};
#endif // MAINWINDOW_H

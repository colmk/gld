#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glw = new GLWidget(this);
    glw->setGeometry(210,150,1121,571);
    ui->listView->setModel(qslm);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Line_clicked()
{
    emit glw->setneedposcntSignal(GLWidget::BuildState::Line);
}


void MainWindow::on_pushButton_Rectangle_clicked()
{
    emit glw->setneedposcntSignal(GLWidget::BuildState::Triangle);
}


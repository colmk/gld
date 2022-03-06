#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glw = new GLWidget(this);
    glw->setGeometry(210,150,1121,571);
}

MainWindow::~MainWindow()
{
    delete ui;
}


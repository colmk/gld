#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glw = new GLWidget(this,ui->listWidget);
    glw->setGeometry(210,150,1121,571);
    ui->listWidget->addItem("泥吼");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Line_clicked()
{
    emit glw->setneedposcntSignal(GLWidget::BuildState::Line);
}

void MainWindow::on_pushButton_Triangle_clicked()
{
    emit glw->setneedposcntSignal(GLWidget::BuildState::Triangle);
}

void MainWindow::on_pushButton_Rectangle_clicked()
{
    emit glw->setneedposcntSignal(GLWidget::BuildState::Rectangle);
}



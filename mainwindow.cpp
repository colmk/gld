#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , qsim(new QStandardItemModel(this))
{
    ui->setupUi(this);
    glw = new GLWidget(this,ui->listWidget, qsim);
    qsim->appendRow(new QStandardItem("Line"));
    qsim->appendRow(new QStandardItem("Triangle"));
    qsim->appendRow(new QStandardItem("Rectangle"));
    //tm = new treeModel(this);
    glw->setGeometry(210,150,1121,571);
    ui->listWidget->addItem("泥吼");
    //ui->treeView->setModel(tm);
    ui->treeView->setModel(qsim);
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



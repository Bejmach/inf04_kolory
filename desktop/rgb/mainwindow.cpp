#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color_label = ui->label;
    result_label = ui->label_9;

    r_label = ui->label_4;
    g_label = ui->label_5;
    b_label = ui->label_8;
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string return_style_sheet(int r, int g, int b){
    std::string style_sheet = "background-color: rgb(" + std::to_string(r) + ", "+std::to_string(g) + ", " + std::to_string(b) + ")";
    return style_sheet;
}

void MainWindow::update_color_label(){
    color_label->setStyleSheet(QString::fromStdString(return_style_sheet(r, g, b)));
}
void MainWindow::update_result_label(){
    result_label->setStyleSheet(QString::fromStdString(return_style_sheet(r, g, b)));
    result_label->setText(QString::fromStdString(std::to_string(r) + ", "+std::to_string(g) + ", " + std::to_string(b)));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    r = value;
    update_color_label();
    r_label->setText(QString::number(r));
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    g = value;
    update_color_label();
    g_label->setText(QString::number(g));
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    b = value;
    update_color_label();
    b_label->setText(QString::number(b));
}


void MainWindow::on_pushButton_pressed()
{
    update_result_label();
}


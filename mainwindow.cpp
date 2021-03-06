#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "pizza.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_PizzaPushButton_clicked()
{
  ui->textEdit->clear();

  auto builder = Pizza::Builder();

  builder.SetDough(Dough(ui->DoughButtonGroup->checkedId()));

  builder.SetPizzaType(PizzaType(ui->PizzaButtonGroup->checkedId()));

  builder.SetOlives(Olive(ui->OlivesButtonGroup->checkedId()));

  builder.SetPepperoni(Pepperoni(ui->PepperoniButtonGroup->checkedId()));

  builder.SetdoubleCheese(DoubleCheese(ui->CheeseButtonGroup->checkedId()));

  builder.SetPineapple(Pineapple(ui->PineapplesButtonGroup->checkedId()));

  auto pizza = builder.build();

  ui->textEdit->setText(pizza.GetOrder());
}

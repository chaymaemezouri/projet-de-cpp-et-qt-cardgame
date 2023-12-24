#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    // Connect signals and slots, initialize widgets, etc.
}

StartDialog::~StartDialog()
{
    delete ui;
}

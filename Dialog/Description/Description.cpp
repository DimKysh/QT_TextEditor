#include "Dialog/Description/Description.h"
#include "ui_DescriptionDlg.h"

DescriptionDialog::DescriptionDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DescriptionDialog)
{
    ui->setupUi(this);
}


DescriptionDialog::~DescriptionDialog()
{
    delete ui;
}

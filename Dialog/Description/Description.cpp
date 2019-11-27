#include "ui_DescriptionDlg.h"

#include "Dialog/Description/Description.h"

DescriptionDialog::DescriptionDialog(QWidget *parent) : QDialog(parent)
                                                      , ui(new Ui::DescriptionDialog)
                                                      , fileModel(QString("./desc.html"))
{
    ui->setupUi(this);
    ui->textBrowserDesc->setText(fileModel.get_fileContent());
}


DescriptionDialog::~DescriptionDialog()
{
    delete ui;
}

#include "ui_DescriptionDlg.h"

#include "Dialog/Description/Description.h"

DescriptionDialog::DescriptionDialog(QWidget *parent) : QDialog(parent)
                                                      , ui(new Ui::DescriptionDialog)
                                                      , fileModel()
{
    isFileOpen = true;

    try
    {
        if(!fileModel.open_descriptionFile())
        {
            throw false;
        }
    }
    catch(bool tmp)
    {
        isFileOpen = tmp;
    }

    ui->setupUi(this);
    ui->textBrowserDesc->setText(fileModel.get_fileContent());
}

bool const & DescriptionDialog::get_isFileOpen() const
{
    return isFileOpen;
}

DescriptionDialog::~DescriptionDialog()
{
    delete ui;
}

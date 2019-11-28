#include "Dialog/MainWindow/MainWindow.h"
#include "Dialog/Description/Description.h"
#include "ui_MainWindow.h"

#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , undoFunctional()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEditMain_textChanged()
{
    QTextCursor cursor(ui->textEditMain->textCursor());

    if(cursor.position() > 0)
    {
       QString strForCheck = ui->textEditMain->toPlainText();

       if(strForCheck.at(cursor.position() - 1) == " " ||
          strForCheck.at(cursor.position() - 1) == "\n" )
       {
          undoFunctional.push_back_element_to_queueForUndo(strForCheck);
       }
    }
}

void MainWindow::on_pushButtonBack_clicked()
{
    QTextCursor cursor;

    ui->textEditMain->setText(undoFunctional.get_last_element_from_queueForUndo());
    ui->textEditMain->textCursor().setPosition(ui->textEditMain->toPlainText().size());
}

void MainWindow::on_pushButtonOpenDesc_clicked()
{
    DescriptionDialog descDlg;

    if(descDlg.get_isFileOpen())
    {
        descDlg.setModal(true);
        descDlg.exec();
    }
}

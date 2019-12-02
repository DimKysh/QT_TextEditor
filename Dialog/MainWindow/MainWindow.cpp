#include "Dialog/MainWindow/MainWindow.h"
#include "Dialog/Description/Description.h"
#include "ui_MainWindow.h"

#include <QMouseEvent>
#include <QFileDialog>
#include <QFile>
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

void MainWindow::on_pushButtonSaveFile_clicked()
{
    this->set_userName();
    QString strUtf8 = "Text file(*.txt);;Binary file(*." + userName + ")";
    QString s = QFileDialog::getSaveFileName(this, "Main title window", QDir::current().path(),QString(trUtf8(strUtf8.toStdString().c_str())));

    if(s.length() > 0)
    {
        int index = s.indexOf("txt");
        QFile file(s);

        if(file.open((QFile::WriteOnly)))
        {
            if(index != -1)
            {
                QTextStream stream(&file);
                stream << ui->textEditMain->toPlainText();
            }
            else {
                  QDataStream stream(&file);
                  QByteArray b = QString("GB_Qt_STUDY").toUtf8();
                  stream.writeRawData(b.data(), b.length());
                  QHash<QChar, int>symbamount;
                  symbamount.clear();
                  QString str = ui->textEditMain->toPlainText();
                  int amount = str.length();
                  QString usedS = "";
                  for (int i = 0; i < amount; ++i) {
                      QChar ch = str.at(i);
                      int index = usedS.indexOf(ch);
                      if (index == -1)
                      {
                          symbamount[ch] = 0;
                          usedS += ch;
                      }
                      else{
                         symbamount[ch]++;
                      }
                  }
                  //********************************
                  for (int i = 0; i < amount; ++i)
                  {
                      QChar chi = usedS[i];

                      for (int j = i + 1; j < amount; ++j)
                      {
                        QChar chj = usedS[j];

                        if (symbamount[chi] < symbamount[chj])
                        {
                            usedS[i] = chj;
                            usedS[j] = chi;
                            chi = chj;
                        }
                      }
                  }
                  symbamount.clear();

                  //**********************************************
                  b = usedS.toUtf8();
                  amount = b.length();
                  stream.writeRawData(reinterpret_cast<char*>(&amount), sizeof amount);
                  stream.writeRawData(b.data(), amount);
                  //***********************************************

                  amount = str.length();
                  for (int i = 0; i < amount; i++)
                  {
                      int index = usedS.indexOf(str.at(i));
                      for (bool w = true; w;)
                      {
                          char wr = index % 128;
                          index /= 128;

                          if (index)
                          {
                              wr |= 0x80;
                              stream.writeRawData(&wr, 1);
                          }
                          else
                          {
                              stream.writeRawData(&wr, 1);
                              w = false;
                          }
                      }
                  }
              }
          file.close();
          }
     }
}


void MainWindow::set_userName()
{
    userName = qgetenv("USER");
    if(userName.isEmpty())
        userName = qgetenv("USERNAME");
    else
        userName = "USER";
}

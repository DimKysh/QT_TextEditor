#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/UndoModel/UndoModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEditMain_textChanged();

    void on_pushButtonBack_clicked();

    void on_pushButtonOpenDesc_clicked();

    void on_pushButtonSaveFile_clicked();

private:
    Ui::MainWindow *ui;
    UndoModel undoFunctional;
    QString userName;
    void set_userName();


};
#endif // MAINWINDOW_H

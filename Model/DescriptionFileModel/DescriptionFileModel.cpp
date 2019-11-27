#include "Model/DescriptionFileModel/DescriptionFileModel.h"

#include <QMessageBox>
#include <QString>

DescriptionFileModel::DescriptionFileModel()
{
    QFile file("./content/desc.html");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        fileContentStr = stream.read(file.size());
    }
    else
    {
        QMessageBox().critical(nullptr,"Critical","Can't open description file.");
    }
}

DescriptionFileModel::DescriptionFileModel(QString const & str)
{
    QFile file(str);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        fileContentStr = stream.read(file.size());
    }
    else
    {
        QMessageBox().critical(nullptr,"Critical","Can't open description file.");
    }
}

DescriptionFileModel::~DescriptionFileModel(){}

//////--GETTERS--//////

QString const & DescriptionFileModel::get_fileContent() const
{
    return fileContentStr;
}

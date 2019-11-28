#include "Model/DescriptionFileModel/DescriptionFileModel.h"

#include <QMessageBox>
#include <QString>
#include <QResource>

DescriptionFileModel::DescriptionFileModel(){}

DescriptionFileModel::~DescriptionFileModel(){}

bool::DescriptionFileModel::open_descriptionFile()
{
    QFile descriptionFile(":/content/desc.html");

    if(descriptionFile.exists())
    {
        if(descriptionFile.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&descriptionFile);
            fileContentStr = stream.read(descriptionFile.size());
        }
        else
        {
            QMessageBox().critical(nullptr,"Critical","Can't open description file.\nCan't open for read.");
            return false;
        }
        return true;
    }
    else
    {
        QMessageBox().critical(nullptr,"Critical","Can't open description file.\nFile doesn't exsist.");
        return false;
    }
}

//////--GETTERS--//////

QString const & DescriptionFileModel::get_fileContent() const
{
    return fileContentStr;
}

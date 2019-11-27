#ifndef _DESCRIPTION_FILE_MODEL_H_
#define _DESCRIPTION_FILE_MODEL_H_

#include <QDir>
#include <QTextStream>

class DescriptionFileModel
{
public:
    explicit DescriptionFileModel();
    DescriptionFileModel(QString const & str = nullptr);
   ~DescriptionFileModel();

    QString const & get_fileContent() const;
private:
    QString fileContentStr;
};



#endif

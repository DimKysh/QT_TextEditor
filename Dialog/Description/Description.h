#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <QDialog>
#include "Model/DescriptionFileModel/DescriptionFileModel.h"

namespace Ui{
class DescriptionDialog;
}

class DescriptionDialog : public QDialog
{
    Q_OBJECT

public:
   explicit DescriptionDialog(QWidget *parent = nullptr);
   virtual ~DescriptionDialog();
   bool const & get_isFileOpen() const;
private:
   bool isFileOpen;
   Ui::DescriptionDialog *ui;
   DescriptionFileModel fileModel;

   };

#endif

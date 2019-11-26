#ifndef _UNDO_MODEL_H_
#define _UNDO_MODEL_H_

#include <QString>
#include <QQueue>

class UndoModel
{
public:
     explicit UndoModel();
    ~UndoModel();

     void pop_front_element_from_queueForUndo();
     QString get_last_element_from_queueForUndo();
     void push_back_element_to_queueForUndo(QString const & elementForPush);

private:
     QQueue<QString> queueForUndo;
};



#endif

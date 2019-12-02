#include "../UndoModel/UndoModel.h"
#include <QDebug>
#include <algorithm>

UndoModel::UndoModel() {}

UndoModel::~UndoModel(){}

//////--SETTERS--//////

void UndoModel::push_back_element_to_queueForUndo(QString const & elementForPush)
{
    if(queueForUndo.size() == 10)
    {
        this->pop_front_element_from_queueForUndo();
    }
    queueForUndo.push_back(elementForPush);
}

//////--GETTERS--//////

void UndoModel::pop_front_element_from_queueForUndo()
{
    queueForUndo.pop_front();
}

QString UndoModel::get_last_element_from_queueForUndo()
{
    QString temp;

    if(queueForUndo.isEmpty())
    {
        return QString("");
    }

    temp = queueForUndo.back();

    queueForUndo.pop_back();

    return temp;
}

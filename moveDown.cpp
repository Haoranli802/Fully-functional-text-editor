//
// Created by Haoran Li on 6/1/21.
//

#include "moveDown.hpp"
void moveDown::execute(EditorModel& model)
{
    oldColumn = model.cursorColumn();
    oldLine = model.cursorLine();
    model.moveDown();
}

void moveDown::undo(EditorModel& model)
{
    model.setCurrentCursor(oldColumn, oldLine);
}
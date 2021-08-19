#include "moveUp.hpp"
void moveUp::execute(EditorModel& model)
{
    oldColumn = model.cursorColumn();
    oldLine = model.cursorLine();
    model.moveUp();
}

void moveUp::undo(EditorModel& model)
{
    model.setCurrentCursor(oldColumn, oldLine);
}
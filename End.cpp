#include "End.hpp"
void End::execute(EditorModel& model)
{
    ColumnIndex = model.cursorColumn();
    oldLine = model.cursorLine();
    model.moveEnd();
}


void End::undo(EditorModel& model)
{
    model.setCurrentCursor(ColumnIndex, oldLine);
}
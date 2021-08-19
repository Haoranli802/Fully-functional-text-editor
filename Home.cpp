#include "Home.hpp"
void Home::execute(EditorModel& model)
{
    oldColumnIndex = model.cursorColumn();
    oldLineIndex = model.cursorLine();
    model.setCurrentCursor(1, oldLineIndex);
}

void Home::undo(EditorModel& model)
{
    model.setCurrentCursor(oldColumnIndex, oldLineIndex);
}
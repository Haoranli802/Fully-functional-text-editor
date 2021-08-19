#include "Delete.hpp"

void Delete::execute(EditorModel& model)
{
    s = model.currentVector();
    oldLineIndex = model.cursorLine();
    oldColumnIndex = model.cursorColumn();
    totalLine = model.lineCount();
    model.deleteCurrent();
}



void Delete::undo(EditorModel& model)
{
    model.setCurrentVector(s);
    model.setCurrentCursor(oldColumnIndex, oldLineIndex);
    model.setTotalLine(totalLine);
}
#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
    s = model.currentVector();
    oldLineIndex = model.cursorLine();
    oldColumnIndex = model.cursorColumn();
    totalLine = model.lineCount();
    model.deleteOneLine();
}

void DeleteLine::undo(EditorModel& model)
{
    model.setCurrentVector(s);
    model.setCurrentCursor(oldColumnIndex, oldLineIndex);
    model.setTotalLine(totalLine);
}
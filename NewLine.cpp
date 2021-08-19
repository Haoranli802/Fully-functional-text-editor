#include "NewLine.hpp"
void NewLine::execute(EditorModel& model)
{
    s = model.currentVector();
    oldColumn = model.cursorColumn();
    oldLine = model.cursorLine();
    totalLine = model.lineCount();
    model.newLine();
}

void NewLine::undo(EditorModel& model)
{
    model.setCurrentVector(s);
    model.setCurrentCursor(oldColumn, oldLine);
    model.setTotalLine(totalLine);
}
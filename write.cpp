#include "write.hpp"

write::write(const char &c)
:newChar{c}
{
}

void write::execute(EditorModel &model)
{
    oldLine = model.line(model.cursorLine());
    oldColumn = model.cursorColumn();
    oldLineIndex = model.cursorLine();
    model.editCurrentLine(newChar);
}

void write::undo(EditorModel &model)
{
    model.setCurrentCursor(oldColumn, oldLineIndex);
    model.setCurrentLine(oldLine);
}
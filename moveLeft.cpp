#include "moveLeft.hpp"

void moveLeft::execute(EditorModel& model)
{
    model.moveCursorLeft();
}


void moveLeft::undo(EditorModel& model)
{
    model.moveCursorRight();
}
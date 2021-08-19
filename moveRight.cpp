#include "moveRight.hpp"

void moveRight::execute(EditorModel& model)
{
    model.moveCursorRight();
}


void moveRight::undo(EditorModel& model)
{
    model.moveCursorLeft();
}
#ifndef MOVEDOWN_HPP
#define MOVEDOWN_HPP

#include "Command.hpp"

// The moveUp class handles moving cursor down in the text editor.


class moveDown : public Command
{
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    int oldColumn;
    int oldLine;

};



#endif

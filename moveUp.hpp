#ifndef MOVEUP_HPP
#define MOVEUP_HPP
#include "Command.hpp"

// The moveUp class handles moving cursor up in the text editor.

class moveUp : public Command
{
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    int oldColumn;
    int oldLine;

};


#endif

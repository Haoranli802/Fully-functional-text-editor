#ifndef MOVERIGHT_HPP
#define MOVERIGHT_HPP

#include "Command.hpp"

// The moveUp class handles moving cursor right in the text editor.


class moveRight : public Command
{
    
    
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;


private:


};

#endif
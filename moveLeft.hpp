#ifndef MOVELEFT_HPP
#define MOVELEFT_HPP


#include "Command.hpp"

// The moveUp class handles moving cursor left in the text editor.


class moveLeft : public Command
{
    
    
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;


private:


};

#endif
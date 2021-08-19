#ifndef NEWLINE_HPP
#define NEWLINE_HPP
#include "Command.hpp"

/*
The newLine class handles creating new lines in the text editor. 
*/

class NewLine : public Command
{
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;


private:
    std::vector<std::string> s;
    int oldLine;
    int oldColumn;
    int totalLine;

};


#endif


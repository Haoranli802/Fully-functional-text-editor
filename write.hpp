#ifndef WRITE_HPP
#define WRITE_HPP

#include "Command.hpp"

// The write class handles writing characters into the text editer

class write : public Command
{
public:

    write(const char& c);

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;


private:
    std::string oldLine;
    char newChar;
    int oldColumn;
    int oldLineIndex;


};



#endif

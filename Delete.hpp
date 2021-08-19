#ifndef DELETE_HPP
#define DELETE_HPP

#include "Command.hpp"

// The Delete class handles deleting characters in the text editor. 

class Delete : public Command
{
public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;


private:
    int oldColumnIndex;
    int oldLineIndex;
    std::vector<std::string> s;
    int totalLine;
};


#endif

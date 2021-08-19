#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

// The DeleteLine class handles deleting lines in the text editor.

class DeleteLine : public Command
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

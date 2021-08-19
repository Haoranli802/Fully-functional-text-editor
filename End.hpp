#ifndef END_HPP
#define END_HPP
#include "Command.hpp"

// The Home class handles moving the cursor beyond the end of the current line 
// in the text editor.

class End : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int ColumnIndex;
    int oldLine;
};


#endif
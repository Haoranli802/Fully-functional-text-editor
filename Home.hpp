#ifndef HOME_HPP
#define HOME_HPP

#include "Command.hpp"

// The Home class handles moving the cursor to the beginning of the current line 
// in the text editor.

class Home : public Command{

public:
    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    int oldLineIndex;
    int oldColumnIndex;

};

#endif
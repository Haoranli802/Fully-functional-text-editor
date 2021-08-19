# Fully-functional-text-editor
This C++ project is based on uci ics ICS45C project #4(stop here and do not look at any part of the project if you are enrolled in this course). It is a fully working text editor that can save your edit into a special file on your computer. The inputs will be Key-pressing on your keyboard, and no outputs will be shown. The only thing you can see if the changes in the text editor.

Here is what you can do with the editor and how you do it.

Any printable character = Insert Character

Inserts a character where the cursor is currently positioned. Any characters at or beyond the cursor on the same line are shifted to the right. The cursor moves one cell to the right afterward.

Ctrl+I = Cursor Up

Moves the cursor up one cell (i.e., to the same column on the previous line). If the previous line is so short that this would place the cursor beyond the end of the previous line, the cursor is placed in the column just beyond the end of the previous line instead. If the cursor is already on line 1, there is no cell above, so this command fails and an error message is displayed.

Ctrl+K = Cursor Down

Moves the cursor down one cell (i.e., to the same column on the next line). If the previous line is so long that this would place the cursor beyond the end of the next line, the cursor is placed in the column just beyond the end of the next line instead. If the cursor is already on the last line, there is no cell below, so this command fails and an error message is displayed.

Ctrl+U = Cursor Left

Moves the cursor left one cell (i.e., to the previous column on the same line). If the cursor is at the beginning of a line already, it instead moves just beyond the end of the previous line instead. If the cursor is at the beginning of line 1, this command fails and an error message is displayed.

Ctrl+O = Cursor Right

Moves the cursor right one cell (i.e., to the next column on the same line). If the cursor is just beyond the end of a line already, it instead moves to the beginning of the next line instead. If the cursor is just beyond the end of the last line, this command fails and an error message is displayed.

Ctrl+Y = Cursor Home

Moves the cursor to the beginning of the current line. No error message is shown if the cursor is already at the beginning of the current line.

Ctrl+P = Cursor End

Moves the cursor just beyond the end of the current line. No error message is shown if the cursor is already at the end of the current line.

Ctrl+J = Ctrl+M = New Line

Creates a new line just under the current line. Any text at or after the cursor on the current line is moved to the beginning of the new line. The cursor is moved to the beginning of the new line. (Note that there are two different keys that are interpreted the same way; either Ctrl+J or Ctrl+M behaves this way.)

Ctrl+H = Backspace

Deletes the character to the left of the current cursor position, sliding subsqeuent characters backward to fill the empty space. Moves the cursor one character to the left. If the cursor is already in column 1, the entire current line of text is instead moved to the end of the previous line and the cursor is placed at the beginning of that moved text. If the cursor is already on line 1 column 1, this command fails and an error message is displayed.

Ctrl+D = Delete Line

Deletes the entire current line of text, with all subsequent lines moving up to fill the empty space. The cursor remains in its current location unless the cursor would be beyond the end of the line of text that now occupies the cursor's line number, in which case the cursor is placed just beyond the end of that line of text instead. If there is only one line of text, it is cleared and the cursor is placed at line 1 column 1. (In other words, the editor must always have at least one line of text, even if it's empty.)

Ctrl+Z = Undo

Reverts the previously-executed command, putting the editor back into the state it was in before that command was executed. All commands listed above are "undoable", including cursor movements and text changes, and individual commands are undone individually (i.e., each "undo" command undoes a single cursor movement, a single character inserted, a single line deleted, etc.).

Ctrl+A = Redo

Re-executes the most-recently-undone command. Note that Undo/Redo work the way that Back and Forward buttons have traditionally worked in a web browser; once you execute a command other than Undo or Redo successfully, there are no commands available to be redone until a command is subsequently undone.

Ctrl+X = Quit/Exit

Exits BooEdit immediately.

source from (https://www.ics.uci.edu/~thornton/ics45c/ProjectGuide/)

After quitting the text editor, it will save all the changes and put the final text a file called test.txt in the same repository as the text editor project.


Luckily, this project also contains automatic tests provided by both the professor and me, which are the gtests (Unit testings).

Implementation instructions: 

The project files are in the app folder. The main.cpp is the execution file, as always.

The gtests files are in the gtest folder.

// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "moveLeft.hpp"
#include "moveRight.hpp"
#include "write.hpp"
#include "Home.hpp"
#include "Delete.hpp"
#include "NewLine.hpp"
#include "DeleteLine.hpp"
#include "moveUp.hpp"
#include "moveDown.hpp"
#include "End.hpp"



// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                case 'A':
                    return Interaction::redo();
                case 'Z':
                    return Interaction::undo();
                case 'X':
                    return Interaction::quit();
                case 'O':
                    return Interaction::command(new moveRight());
                case 'U':
                    return Interaction::command(new moveLeft());
                case 'Y':
                    return Interaction::command(new Home());
                case 'H':
                    return Interaction::command(new Delete());
                case 'M':
                    return Interaction::command(new NewLine());
                case 'J':
                    return Interaction::command(new NewLine());
                case 'D':
                    return Interaction::command(new DeleteLine());
                case 'I':
                    return Interaction::command(new moveUp());
                case 'K':
                    return Interaction::command(new moveDown());
                case 'P':
                    return Interaction::command(new End());

            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            return Interaction::command(new write(keypress.code()));
        }
    }
}
// InteractionProcessor.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>




// This function implements command execution
// This also handles redo and undo by creating two vectors of commands 
// and implement the last in first out feature
// once a command besides undo is excuted, all commands in redo is cleared and delete
// once everything is done, all commands in undo and redo is cleared and delete
// to prevent memory leaks

void InteractionProcessor::run()
{
    view.refresh();
    std::vector<Command*> undoList;
    std::vector<Command*> redoList;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();
        if (interaction.type() == InteractionType::quit)
        {
            model.moveTextToFile();
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if(!undoList.empty())
            {
                undoList.back()->undo(model);
                model.clearErrorMessage();
                redoList.push_back(undoList.back());
                undoList.pop_back();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if(!redoList.empty())
            {
                redoList.back()->execute(model);
                model.clearErrorMessage();
                undoList.push_back(redoList.back());
                redoList.pop_back();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                for(auto& j : redoList)
                {
                    delete j;
                }
                redoList.clear();
                undoList.push_back(command);
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
        }
        model.setMaxColumn();
    }
    for(auto& i : undoList)
    {
        delete i;
    }
    for(auto& j : redoList)
    {
        delete j;
    }
}
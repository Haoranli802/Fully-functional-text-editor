// EditorModel.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <fstream>
#include <algorithm>



EditorModel::EditorModel()
{
}


int EditorModel::cursorLine() const
{
    return currentLineIndex;
}


int EditorModel::cursorColumn() const
{
    return currentColumnIndex;
}


int EditorModel::lineCount() const
{
    return totalLine;
}


void EditorModel::moveCursorRight()
{
    if(currentColumnIndex < maxColumn)
    {
        currentColumnIndex ++;
    }

    else if(currentColumnIndex == maxColumn and currentLineIndex < totalLine)
    {
        currentColumnIndex = 1;
        currentLineIndex ++;
    }
    else
    {
        throw EditorException{"Already at end"};
    }
}


void EditorModel::moveCursorLeft()
{
    if(currentColumnIndex > 1)
    {
        currentColumnIndex --;
    }
    else if(currentColumnIndex == 1 and currentLineIndex > 1)
    {
        currentLineIndex --;
        currentColumnIndex = line(currentLineIndex).length() + 1;
    }
    else
    {
        throw EditorException{"Already at beginning"};
    }
}

const std::string& EditorModel::line(int lineNumber) const
{
    return textVector[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return currentMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    currentMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    currentMessage = "";
}



void EditorModel::setCurrentLine(const std::string& s)
{
    textVector.at(currentLineIndex-1) = s;
}

void EditorModel::setCurrentCursor(int column, int line)
{
    currentColumnIndex = column;
    currentLineIndex = line;
}

void EditorModel::editCurrentLine(const char& c)
{
    std::string temp = std::string( 1, c );
    textVector.at(currentLineIndex-1).insert(currentColumnIndex-1, temp);
    currentColumnIndex ++;
    maxColumn ++;
}


void EditorModel::setMaxColumn()
{
    maxColumn = textVector.at(currentLineIndex-1).length();
    maxColumn ++;
}

void EditorModel::deleteCurrent()
{
    if(currentLineIndex == 1 and currentColumnIndex == 1)
    {
        throw EditorException{"Already at beginning"};
    }
    else if(currentColumnIndex == 1 and currentLineIndex > 1)
    {
        this->moveCursorLeft();
        std::string temp = textVector.at(currentLineIndex - 1);
        textVector.erase(textVector.begin() + currentLineIndex -1, textVector.begin() + currentLineIndex);
        textVector.at(currentLineIndex - 1) = temp + textVector.at(currentLineIndex - 1);
        totalLine --;
    }
    else
    {
        this->moveCursorLeft();
        textVector.at(currentLineIndex - 1).erase(textVector.at(currentLineIndex-1).begin() + currentColumnIndex - 1, textVector.at(currentLineIndex-1).begin() + currentColumnIndex);
    }

}


std::vector<std::string> EditorModel::currentVector()
{
    return this->textVector;
}

void EditorModel::setCurrentVector(std::vector<std::string>& s)
{
    this->textVector = s;
}


void EditorModel::newLine()
{
    totalLine ++;
    if(currentColumnIndex == maxColumn)
    {
        textVector.insert(textVector.begin() + currentLineIndex, "");
        this->moveCursorRight();
    }
    else
    {
        std::string temp = textVector.at(currentLineIndex - 1).substr(currentColumnIndex - 1, -1);
        textVector.at(currentLineIndex - 1) = textVector.at(currentLineIndex - 1).substr(0, currentColumnIndex - 1);
        textVector.insert(textVector.begin() + currentLineIndex, temp);
        currentLineIndex++;
        currentColumnIndex = 1;
    }
}

void EditorModel::setTotalLine(int totalLines)
{
    this->totalLine = totalLines;
}


void EditorModel::deleteOneLine()
{
    if(totalLine == 1)
    {
        if(textVector.at(currentLineIndex - 1) != "")
        {
            textVector.at(currentLineIndex - 1) = "";
            currentColumnIndex = 1;
        }
        else
        {
            throw EditorException{"Already empty"};
        }
        
        return;
    }
    else if(currentLineIndex == totalLine and currentLineIndex > 1 and currentColumnIndex > textVector.at(currentLineIndex - 2).length())
    {
        currentColumnIndex = textVector.at(currentLineIndex - 2).length();
        currentColumnIndex ++;
        textVector.erase(textVector.begin() + currentLineIndex -1, textVector.begin() + currentLineIndex);
    }
    else if(currentLineIndex != totalLine and currentLineIndex > 1 and currentColumnIndex > textVector.at(currentLineIndex).length())
    {
        currentColumnIndex = textVector.at(currentLineIndex).length();
        currentColumnIndex ++;
        textVector.erase(textVector.begin() + currentLineIndex -1, textVector.begin() + currentLineIndex);
    }
    else
    {
        textVector.erase(textVector.begin() + currentLineIndex -1, textVector.begin() + currentLineIndex);
    }

    if(currentLineIndex == totalLine)
    {
        currentLineIndex --;
    }
    totalLine --;
}




void EditorModel::moveUp()
{
    if(cursorLine() == 1)
    {
        throw EditorException{"Already at top"};
    }
    else if(currentColumnIndex > textVector.at(currentLineIndex - 2).length())
    {
        currentColumnIndex = textVector.at(currentLineIndex - 2).length();
        currentColumnIndex ++;
        currentLineIndex --;
    }
    else
    {
        currentLineIndex --;
    }
}


void EditorModel::moveDown()
{
    if(cursorLine() == totalLine)
    {
        throw EditorException{"Already at bottom"};
    }
    else if(currentColumnIndex > textVector.at(currentLineIndex).length())
    {
        currentColumnIndex = textVector.at(currentLineIndex).length();
        currentColumnIndex ++;
        currentLineIndex ++;
    }
    else
    {
        currentLineIndex ++;
    }
}

void EditorModel::moveEnd()
{
    currentColumnIndex = textVector.at(currentLineIndex - 1).length();
    currentColumnIndex ++;
}

void EditorModel::moveTextToFile()
{
    std::filebuf fb;
    fb.open ("text.txt",std::ios::out);
    std::ostream os(&fb);
    std::for_each(textVector.begin(), textVector.end(), [&](std::string &n){ os << n << std::endl;});
}
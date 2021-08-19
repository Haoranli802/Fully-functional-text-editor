// MockKeypressReader.cpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// Implementation of the MockKeypressReader class
//
// DO NOT MODIFY THIS FILE

#include "MockKeypressReader.hpp"
#include "NoMoreKeypressesException.hpp"


MockKeypressReader::MockKeypressReader()
    : nextKeypressIndex{0}
{
}


MockKeypressReader::MockKeypressReader(const std::vector<Keypress>& keypresses)
    : keypresses{keypresses}, nextKeypressIndex{0}
{
}


Keypress MockKeypressReader::nextKeypress()
{
    if (nextKeypressIndex >= keypresses.size())
    {
        throw NoMoreKeypressesException{};
    }
    else
    {
        Keypress& next = keypresses[nextKeypressIndex];
        ++nextKeypressIndex;
        return next;
    }
}


void MockKeypressReader::addKeypresses(const std::vector<Keypress>& keypressesToAdd)
{
    keypresses.insert(keypresses.end(), keypressesToAdd.begin(), keypressesToAdd.end());
}


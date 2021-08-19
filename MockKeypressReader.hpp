// MockKeypressReader.hpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// A derived class of KeypressReader that you construct by giving it a
// vector of Keypresses.  Instead of reading its keypresses from the
// keyboard, it simply returns the keypresses in that vector, in the
// order specified.
//
// DO NOT MODIFY THIS FILE

#ifndef MOCKKEYPRESSREADER_HPP
#define MOCKKEYPRESSREADER_HPP

#include <vector>
#include "KeypressReader.hpp"



class MockKeypressReader : public KeypressReader
{
public:
    MockKeypressReader();
    explicit MockKeypressReader(const std::vector<Keypress>& keypresses);

    Keypress nextKeypress() override;

    void addKeypresses(const std::vector<Keypress>& keypressesToAdd);

private:
    std::vector<Keypress> keypresses;
    int nextKeypressIndex;
};



#endif


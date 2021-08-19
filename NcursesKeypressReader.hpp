// NcursesKeypressReader.hpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// This is a derived class of KeypressReader, which reads keypresses from
// the keyboard using a library called "ncurses".
//
// DO NOT MODIFY THIS FILE

#ifndef NCURSESKEYPRESSREADER_HPP
#define NCURSESKEYPRESSREADER_HPP

#include "KeypressReader.hpp"



class NcursesKeypressReader : public KeypressReader
{
public:
    Keypress nextKeypress() override;
};



#endif


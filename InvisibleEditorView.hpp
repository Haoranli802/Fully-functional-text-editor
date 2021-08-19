// InvisibleEditorView.hpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// A derived class of EditorView, which has empty implementations of all of
// its virtual member functions.  Setting up BooEdit with an InvisibleEditorView
// will result in a version of BooEdit that displays no user interface, which is
// exactly what you want if you're going to unit test parts of BooEdit.
//
// DO NOT MODIFY THIS FILE

#ifndef INVISIBLEEDITORVIEW_HPP
#define INVISIBLEEDITORVIEW_HPP

#include "EditorView.hpp"



class InvisibleEditorView : public EditorView
{
public:
    void start() override { }
    void stop() override { }
    void refresh() override { }
};



#endif


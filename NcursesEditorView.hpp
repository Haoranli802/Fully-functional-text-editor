// NcursesEditorView.hpp
//
// ICS 45C Spring 2021
// Project #4: People Just Love to Play with Words
//
// A derived class of EditorView, which visualizes the current state of
// BooEdit using a library called "ncurses".
//
// DO NOT MODIFY THIS FILE

#ifndef NCURSESEDITORVIEW_HPP
#define NCURSESEDITORVIEW_HPP

#include "EditorModel.hpp"
#include "EditorView.hpp"



class NcursesEditorView : public EditorView
{
public:
    explicit NcursesEditorView(EditorModel& model);

    void start() override;
    void stop() override;
    void refresh() override;

private:
    EditorModel& model;

    int topVisibleLine;
    int leftVisibleColumn;
};



#endif


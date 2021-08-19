// MockInteractionReader.hpp
//
// ICS 45C Spring 2021
// Project #4: People Just Want to Play with Words
//
// A derived class of InteractionReader that is constructed with a vector of
// Interactions.  Rather than reading the interactions from the keyboard,
// it returns the Interactions in that vector, in the order specified,
// returning an Interaction::quit() when there are no more interactions
// in the vector.
//
// DO NOT MODIFY THIS FILE

#ifndef MOCKINTERACTIONREADER_HPP
#define MOCKINTERACTIONREADER_HPP

#include <vector>
#include "InteractionReader.hpp"



class MockInteractionReader : public InteractionReader
{
public:
    explicit MockInteractionReader(const std::vector<Interaction>& interactions);
    Interaction nextInteraction() override;

private:
    std::vector<Interaction> interactions;
    unsigned int nextInteractionIndex;
};



#endif


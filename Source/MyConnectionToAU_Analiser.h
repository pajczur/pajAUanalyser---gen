/*
  ==============================================================================

    MyConnectionToAU_Analiser.h
    Created: 13 Sep 2018 11:08:59pm
    Author:  Wojtek Pilwinski

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "WavesGen.h"

//==============================================================================
/*
*/
class MyConnectionToAU_Analiser    : public InterprocessConnection
{
public:
    MyConnectionToAU_Analiser();
    ~MyConnectionToAU_Analiser();
    
    void connectionMade() override;
    void connectionLost() override;
    void messageReceived( const MemoryBlock & message) override;

    WavesGen *connectedWaveGen;
    bool pajTurnON;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyConnectionToAU_Analiser)
};

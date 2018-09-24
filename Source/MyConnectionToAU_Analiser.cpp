/*
  ==============================================================================

    MyConnectionToAU_Analiser.cpp
    Created: 13 Sep 2018 11:08:59pm
    Author:  Wojtek Pilwinski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MyConnectionToAU_Analiser.h"

//==============================================================================
MyConnectionToAU_Analiser::MyConnectionToAU_Analiser()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    pajTurnON = false;
}

MyConnectionToAU_Analiser::~MyConnectionToAU_Analiser()
{
}


void MyConnectionToAU_Analiser::connectionMade()
{
}

void MyConnectionToAU_Analiser::connectionLost()
{
}

void MyConnectionToAU_Analiser::messageReceived( const MemoryBlock & message)
{
    int pajImpID = message[0];
    
    switch (pajImpID)
    {
        case wMute:
            connectedWaveGen->wSetImpulse(wMute);
            pajTurnON = false;
            break;
        case w1024:
            connectedWaveGen->wSetImpulse(w1024);
            pajTurnON = true;
            break;
        case w2048:
            connectedWaveGen->wSetImpulse(w2048);
            pajTurnON = true;
            break;
        case w4096:
            connectedWaveGen->wSetImpulse(w4096);
            pajTurnON = true;
            break;
        case w8192:
            connectedWaveGen->wSetImpulse(w8192);
            pajTurnON = true;
            break;
        case w16384:
            connectedWaveGen->wSetImpulse(w16384);
            pajTurnON = true;
            break;
        case w32768:
            connectedWaveGen->wSetImpulse(w32768);
            pajTurnON = true;
            break;
        case w65536:
            connectedWaveGen->wSetImpulse(w65536);
            pajTurnON = true;
            break;
            
        default:
            break;
    }
}

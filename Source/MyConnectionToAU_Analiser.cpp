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
        case MUTE_IMPULSE_ID:
            connectedWaveGen->wSetImpulse(MUTE_IMPULSE_ID);
            pajTurnON = false;
            break;
        case B_1024ID:
            connectedWaveGen->wSetImpulse(B_1024ID);
            pajTurnON = true;
            break;
        case B_2048ID:
            connectedWaveGen->wSetImpulse(B_2048ID);
            pajTurnON = true;
            break;
        case B_4096ID:
            connectedWaveGen->wSetImpulse(B_4096ID);
            pajTurnON = true;
            break;
        case B_8192ID:
            connectedWaveGen->wSetImpulse(B_8192ID);
            pajTurnON = true;
            break;
        case B_16384ID:
            connectedWaveGen->wSetImpulse(B_16384ID);
            pajTurnON = true;
            break;
        case B_32768ID:
            connectedWaveGen->wSetImpulse(B_32768ID);
            pajTurnON = true;
            break;
        case B_65536ID:
            connectedWaveGen->wSetImpulse(B_65536ID);
            pajTurnON = true;
            break;
            
        default:
            break;
    }
}

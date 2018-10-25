/*
  ==============================================================================

    WavesGen.cpp
    Created: 17 Apr 2018 7:53:29pm
    Author:  Wojtek Pilwinski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WavesGen.h"
#include <cmath>
#include <iostream>


//==============================================================================
WavesGen::WavesGen() :
                    wSampleRate(0.0),
                    phase_i(-1),
                    pajPlay(false)
{
}

WavesGen::~WavesGen()
{
}

void WavesGen::settings(double sampRate, int buffsize)
{
    wSampleRate = sampRate;
    wBufferSize = buffsize;
    
    phase_i = -1;
}


void WavesGen::wSetImpulse(int wImpID)
{
    switch (wImpID)
    {
        case MUTE_IMPULSE_ID:
            pajPhase = -1;
            pajBuff = MUTE_IMPULSE_ID;
            break;
            
        case B_1024ID:
            pajPhase = 1024;
            pajBuff = B_1024ID;
            break;
            
        case B_2048ID:
            pajPhase = 2048;
            pajBuff = B_2048ID;
            break;
            
        case B_4096ID:
            pajPhase = 4096;
            pajBuff = B_4096ID;
            break;
            
        case B_8192ID:
            pajPhase = 8192;
            pajBuff = B_8192ID;
            break;
            
        case B_16384ID:
            pajPhase = 16384;
            pajBuff = B_16384ID;
            break;
            
        case B_32768ID:
            pajPhase = 32768;
            pajBuff = B_32768ID;
            break;
            
        case B_65536ID:
            pajPhase = 65536;
            pajBuff = B_65536ID;
            break;
            
        default:
            pajPhase = -1;
            break;
    }
    
    
    if(wImpID==MUTE_IMPULSE_ID) pajPlay=false;
    else                        pajPlay=true;
}


void WavesGen::playImpulse(AudioBuffer<float> &outputBuffer, float bufSize, int channelQuantity)
{

    if(pajPlay)
    {
        float* channelData[channelQuantity];
        channelData[0] = outputBuffer.getWritePointer (0);
        if(channelQuantity>1)
            channelData[1] = outputBuffer.getWritePointer (1);
        
        for (int sample=0; sample<bufSize; sample++)
        {
            double voice = pajImp();

            for(int channel=0; channel<channelQuantity; ++channel)
            {
                channelData[channel][sample] = voice;
            }
        }
    }
    else
    {
        return;
    }
}

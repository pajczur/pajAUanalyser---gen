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


void WavesGen::wSetImpulse(impulseID wImp)
{
    switch (wImp)
    {
        case wMute:
            pajPhase = -1;
            pajBuff = wMute;
            break;
            
        case w1024:
            pajPhase = 1024;
            pajBuff = w1024;
            break;
            
        case w2048:
            pajPhase = 2048;
            pajBuff = w2048;
            break;
            
        case w4096:
            pajPhase = 4096;
            pajBuff = w4096;
            break;
            
        case w8192:
            pajPhase = 8192;
            pajBuff = w8192;
            break;
            
        case w16384:
            pajPhase = 16384;
            pajBuff = w16384;
            break;
            
        case w32768:
            pajPhase = 32768;
            pajBuff = w32768;
            break;
            
        case w65536:
            pajPhase = 65536;
            pajBuff = w65536;
            break;
            
        default:
            pajPhase = -1;
            break;
    }
    
    
    if(wImp==wMute) pajPlay=false;
    else            pajPlay=true;
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

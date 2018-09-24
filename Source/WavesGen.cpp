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
//    wImpulseID = wImp;
    
    switch (wImp)
    {
        case wMute:
            pajPhase = -1;
            break;
            
        case w1024:
            pajPhase = 1024;
            break;
            
        case w2048:
            pajPhase = 2048;
            break;
            
        case w4096:
            pajPhase = 4096;
            break;
            
        case w8192:
            pajPhase = 8192;
            break;
            
        case w16384:
            pajPhase = 16384;
            break;
            
        case w32768:
            pajPhase = 32768;
            break;
            
        case w65536:
            pajPhase = 65536;
            break;
            
        default:
            pajPhase = -1;
            break;
    }
    
    
    if(wImp==wMute) pajPlay=false;
    else            pajPlay=true;
}

//double WavesGen::impulseOscillator(int wImpID)
//{
//    switch (wImpID)
//    {
//        case wMute:
//            return 0.0;
//
//        case w1024:
//            return imp1024();
//
//        case w2048:
//            return imp2048();
//
//        case w4096:
//            return imp4096();
//
//        case w8192:
//            return imp8192();
//
//        case w16384:
//            return imp16384();
//
//        case w32768:
//            return imp32768();
//
//        case w65536:
//            return imp65536();
//
//        default:
//            return 0.0;
//    }
//}


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
//            double voice = impulseOscillator(wImpulseID);
            double voice = pajImp();

            for(int channel=0; channel<channelQuantity; ++channel)
            {
//                outputBuffer.addSample(channel, sample, voice);
                channelData[channel][sample] = voice;
            }
        }
    }
}

//int WavesGen::getImpulseID()
//{
//    return wImpulseID;
//}

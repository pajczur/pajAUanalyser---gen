/*
  ==============================================================================

    WavesGen.h
    Created: 17 Apr 2018 7:53:29pm
    Author:  Wojtek Pilwinski

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/

#define B_1024ID        0
#define B_2048ID        1
#define B_4096ID        2
#define B_8192ID        3
#define B_16384ID       4
#define B_32768ID       5
#define B_65536ID       6
#define MUTE_IMPULSE_ID 7


class WavesGen
{
public:
    WavesGen();
    ~WavesGen();
    void settings(double sampRate, int buffsize);
    
private:
    
    inline int pajImp() { phase_i++; if(phase_i>=pajPhase)phase_i=0; if(phase_i==0)return 1;else return 0;}
    
    
public:
    void wSetImpulse(int wImpID);
    void playImpulse(AudioBuffer<float> &outputBuffer, float bufferSize, int channelQuantity);

private:
    double wSampleRate;
    int    wBufferSize;
public:
    int pajPhase;
    int phase_i;
    int pajBuff;

    
    std::atomic<bool> pajPlay;
};

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

enum impulseID
{
    wMute  = 0,
    w1024  = 1,
    w2048  = 2,
    w4096  = 3,
    w8192  = 4,
    w16384 = 5,
    w32768 = 6,
    w65536 = 7
};


class WavesGen
{
public:
    WavesGen();
    ~WavesGen();
    void settings(double sampRate, int buffsize);
    
private:
    
    inline int pajImp() { phase_i++; if(phase_i>=pajPhase)phase_i=0; if(phase_i==0)return 1;else return 0;}
    
    
public:
    void wSetImpulse(impulseID wImp);
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

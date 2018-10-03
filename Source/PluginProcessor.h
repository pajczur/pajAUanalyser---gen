/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once
#include <atomic>
#include "../JuceLibraryCode/JuceHeader.h"
#include "MyConnectionToAU_Analiser.h"

//==============================================================================
/**
 */
class PajImpulseAudioProcessor  : public AudioProcessor, public InterprocessConnectionServer, public Timer
{
public:
    //==============================================================================
    PajImpulseAudioProcessor();
    ~PajImpulseAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    WavesGen waves;
    
    //    void connectionMade() override;
    //    void connectionLost() override;
    //    void messageReceived( const MemoryBlock & message) override;
    InterprocessConnection* createConnectionObject() override;
    
    MyConnectionToAU_Analiser pajConnection;
    void timerCallback() override;
private:
    int sampleIntL=0;
    int sampleIntR=0;
    
    std::atomic<int> bypassTmier;
    std::atomic<int> bypassTreshold;
    
    MemoryBlock wMuteMessage;
    
    bool sendBypassMessage;

public:
    enum buttonsID {
        pajOffButtonID      = 110
    };
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PajImpulseAudioProcessor)
};

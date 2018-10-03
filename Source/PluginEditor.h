/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PajImpulseAudioProcessorEditor  : public AudioProcessorEditor, public Timer
{
public:
    PajImpulseAudioProcessorEditor (PajImpulseAudioProcessor&);
    ~PajImpulseAudioProcessorEditor();
    
    void updateToggleState(Button* button, int waveIdentifier);
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void timerCallback() override;
    
private:
    PajImpulseAudioProcessor& processor;
    
    Rectangle<float> logoSpace;
    const String pathToLogo = "/Users/wojtekpilwinski/Development/PublicRepositories/pajAUanalyser - gen/Source/pajczurLogo.png";
    File pajLogoFile = pathToLogo ;
    Image pajLogo = ImageFileFormat::loadFrom(pajLogoFile);
    
    // Buttons
    TextButton wMuteButton;
    
    MemoryBlock wMuteMessage;
    
    Label temppp;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PajImpulseAudioProcessorEditor)
};

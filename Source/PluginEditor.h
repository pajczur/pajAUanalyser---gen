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
class PajImpulseAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    PajImpulseAudioProcessorEditor (PajImpulseAudioProcessor&);
    ~PajImpulseAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    PajImpulseAudioProcessor& processor;
    
    Rectangle<float> logoSpace;
    Image pajLogo = ImageCache::getFromMemory(pajImpulse::pajLogoYellow_png, pajImpulse::pajLogoYellow_pngSize);
    
    Rectangle<float> wallPaperSpace;
    Image pajWallPaper = ImageCache::getFromMemory(pajImpulse::impulseIcon_png, pajImpulse::impulseIcon_pngSize);
    
    MemoryBlock wMuteMessage;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PajImpulseAudioProcessorEditor)
};

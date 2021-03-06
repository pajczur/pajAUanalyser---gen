/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

//#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PajImpulseAudioProcessorEditor::PajImpulseAudioProcessorEditor (PajImpulseAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    setSize (300, 300);
    
    logoSpace.setBounds(4.5, 5, 48, 48);
    wallPaperSpace.setBounds(0, 0, getWidth(), getHeight());
    
    wMuteMessage.setSize(1);
    wMuteMessage.fillWith(10);
}

PajImpulseAudioProcessorEditor::~PajImpulseAudioProcessorEditor()
{
}

//==============================================================================
void PajImpulseAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);

    g.drawImage(pajWallPaper, wallPaperSpace);
    g.drawImage(pajLogo, logoSpace);
}

void PajImpulseAudioProcessorEditor::resized()
{
}

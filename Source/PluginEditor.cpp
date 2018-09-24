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
    
    addAndMakeVisible(&wMuteButton);
    wMuteButton.setButtonText("Turn OFF");
    wMuteButton.onClick = [this] { updateToggleState(&wMuteButton, wMute); };
    wMuteButton.setBounds        (100, 100, 100, 100);
    logoSpace.setBounds(4.5, 5, 40, 40);
    
    wMuteMessage.setSize(1);
    wMuteMessage.fillWith(10);
}

PajImpulseAudioProcessorEditor::~PajImpulseAudioProcessorEditor()
{
}

//==============================================================================
void PajImpulseAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::indigo);
    
    g.setColour (Colours::lightblue);
    
    //    g.drawRect(margX, 5, 600, 40);
    g.drawRoundedRectangle(logoSpace, 10.f, 1.0f);
    g.drawImage(pajLogo, logoSpace);
}

void PajImpulseAudioProcessorEditor::resized()
{
}




void PajImpulseAudioProcessorEditor::updateToggleState(Button* button, int waveIdentifier)
{
    processor.waves.wSetImpulse(wMute);
    
    if(processor.pajConnection.pajTurnON)
    {
        int milisecondsToWait = roundToInt(2000.0f*(double)processor.waves.pajPhase / processor.getSampleRate());
        
        startTimer(milisecondsToWait);
    }
}


void PajImpulseAudioProcessorEditor::timerCallback()
{
    stopTimer();
    processor.pajConnection.sendMessage(wMuteMessage);
}

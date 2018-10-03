/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PajImpulseAudioProcessor::PajImpulseAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    wMuteMessage.setSize(1);
    wMuteMessage.fillWith(10);
    pajConnection.connectedWaveGen = &waves;
    beginWaitingForSocket(52425);
//    sendBypassMessage = false;
    bypassTreshold = -1;
}

PajImpulseAudioProcessor::~PajImpulseAudioProcessor()
{
    stop();
}

//==============================================================================
const String PajImpulseAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PajImpulseAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PajImpulseAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PajImpulseAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PajImpulseAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PajImpulseAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PajImpulseAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PajImpulseAudioProcessor::setCurrentProgram (int index)
{
}

const String PajImpulseAudioProcessor::getProgramName (int index)
{
    return {};
}

void PajImpulseAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PajImpulseAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    sendBypassMessage = false;
    bypassTreshold = -1;
    
    if(!pajConnection.isConnected())
        beginWaitingForSocket(52425);
    
    if(isTimerRunning())
         stopTimer();
    
    bypassTmier = round(((float)samplesPerBlock * 1000.0f) / sampleRate);
    startTimer(bypassTmier);
}

void PajImpulseAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PajImpulseAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PajImpulseAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    bypassTreshold=1;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    const int buffSize = buffer.getNumSamples();
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    waves.playImpulse(buffer, buffSize, totalNumOutputChannels);
}

//==============================================================================
bool PajImpulseAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PajImpulseAudioProcessor::createEditor()
{
    return new PajImpulseAudioProcessorEditor (*this);
}

//==============================================================================
void PajImpulseAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PajImpulseAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

InterprocessConnection* PajImpulseAudioProcessor::createConnectionObject()
{
    return &pajConnection;
}

void PajImpulseAudioProcessor::timerCallback()
{
    if(pajConnection.isConnected())
    {
        if(bypassTreshold < 0)
        {
            if(sendBypassMessage)
            {
                MemoryBlock impulseMessage;
                impulseMessage.setSize(1);
                impulseMessage.fillWith(pajOffButtonID);
                pajConnection.sendMessage(impulseMessage);
                sendBypassMessage = false;
            }
        }
        else
        {
            bypassTreshold--;
            
            if(!sendBypassMessage)
            {
                sendBypassMessage = true;
                MemoryBlock impulseMessage;
                impulseMessage.setSize(1);
                impulseMessage.fillWith(waves.pajBuff);
                pajConnection.sendMessage(impulseMessage);
            }
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PajImpulseAudioProcessor();
}

/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

//==============================================================================
FaderAudioProcessorEditor::FaderAudioProcessorEditor (FaderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    GainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    GainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    GainSlider.addListener(this);
    GainSlider.setRange(-60.0f, 0.0f, 0.01f);
    GainSlider.setValue(-12.0);
    
    
    addAndMakeVisible(GainSlider);
  
    setSize (200, 300);
}

FaderAudioProcessorEditor::~FaderAudioProcessorEditor()
{
}

//==============================================================================
void FaderAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll (Colours::transparentBlack);
}

void FaderAudioProcessorEditor::resized()
{
    GainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void FaderAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if (slider ==  &GainSlider)
    {
        processor.gain = GainSlider.getValue();
    }
}

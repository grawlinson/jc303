#include "Gui.h"

//==============================================================================
JC303Editor::JC303Editor (JC303& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processorRef (p), valueTreeState (vts)
{
    // Create and configure rotary sliders for each parameter
    addAndMakeVisible(waveformSlider = createSlider());
    addAndMakeVisible(tuningSlider = createSlider());
    addAndMakeVisible(cutoffFreqSlider = createSlider());
    addAndMakeVisible(resonanceSlider = createSlider());
    addAndMakeVisible(envelopModSlider = createSlider());
    addAndMakeVisible(decaySlider = createSlider());
    addAndMakeVisible(accentSlider = createSlider());
    addAndMakeVisible(volumeSlider = createSlider());

    // attch controls to processor parameters tree
    waveformAttachment.reset (new SliderAttachment (valueTreeState, "waveform", *waveformSlider));
    tuningAttachment.reset (new SliderAttachment (valueTreeState, "tuning", *tuningSlider));
    cutoffFreqAttachment.reset (new SliderAttachment (valueTreeState, "cutoff", *cutoffFreqSlider));
    resonanceAttachment.reset (new SliderAttachment (valueTreeState, "resonance", *resonanceSlider));
    envelopModAttachment.reset (new SliderAttachment (valueTreeState, "envmod", *envelopModSlider));
    decayAttachment.reset (new SliderAttachment (valueTreeState, "decay", *decaySlider));
    accentAttachment.reset (new SliderAttachment (valueTreeState, "accent", *accentSlider));
    volumeAttachment.reset (new SliderAttachment (valueTreeState, "volume", *volumeSlider));

    setControlsLayout();

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (745, 288);
}

JC303Editor::~JC303Editor()
{
}

//==============================================================================
void JC303Editor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);

    // main gui is a simple background with labels
    juce::Image background = ImageCache::getFromMemory (BinaryData::jc303gui_png, BinaryData::jc303gui_pngSize);
    g.drawImageAt (background, 0, 0);
}

void JC303Editor::resized()
{
    setControlsLayout();
}

juce::Slider* JC303Editor::createSlider()
{
    auto* slider = new juce::Slider();
    slider->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider->setLookAndFeel(&lookAndFeel);
    slider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    //slider->setRange(parameter->range.start, parameter->range.end);
    //slider->setValue(*parameter);
    //slider->addListener(this);
    return slider;
}

void JC303Editor::setControlsLayout()
{
    // Set the bounds and other properties for each slider
    // Adjust the parameters accordingly to fit your needs
    const int sliderWidth = 120;
    const int sliderHeight = 120;

    // knob positioning location
    // first row
    pair<int, int> waveFormLocation = {9, 20}; 
    pair<int, int> volumeLocation = {130, 20}; 
    // second row
    pair<int, int> tuningLocation = {9, 160}; 
    pair<int, int> cutoffFreqLocation = {130, 160}; 
    pair<int, int> resonanceLocation = {252, 160}; 
    pair<int, int> envelopeLocation = {374, 160}; 
    pair<int, int> decayLocation = {496, 160}; 
    pair<int, int> accentLocation = {618, 160}; 

    waveformSlider->setBounds(waveFormLocation.first, waveFormLocation.second, sliderWidth, sliderHeight);
    volumeSlider->setBounds(volumeLocation.first, volumeLocation.second, sliderWidth, sliderHeight);
    tuningSlider->setBounds(tuningLocation.first, tuningLocation.second, sliderWidth, sliderHeight);
    cutoffFreqSlider->setBounds(cutoffFreqLocation.first, cutoffFreqLocation.second, sliderWidth, sliderHeight);
    resonanceSlider->setBounds(resonanceLocation.first, resonanceLocation.second, sliderWidth, sliderHeight);
    envelopModSlider->setBounds(envelopeLocation.first, envelopeLocation.second, sliderWidth, sliderHeight);
    decaySlider->setBounds(decayLocation.first, decayLocation.second, sliderWidth, sliderHeight);
    accentSlider->setBounds(accentLocation.first, accentLocation.second, sliderWidth, sliderHeight);
}
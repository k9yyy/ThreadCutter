#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ThreadCutterAudioProcessorEditor : public AudioProcessorEditor, private Slider::Listener, private Button::Listener
{
public:
	ThreadCutterAudioProcessorEditor(ThreadCutterAudioProcessor&);
	~ThreadCutterAudioProcessorEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

private:
	void sliderValueChanged(Slider* slider) override;
	void buttonClicked(Button* button) override;

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	ThreadCutterAudioProcessor& processor;

	double a = 0.5;
	ProgressBar test;
	Slider mfccScoreOffsetSlider;
	Slider mfccScoreScaleSlider;
	Slider thresholdSlider;
	TextButton doSampleButton[3];
	ToggleButton enableSampleButton[3];

	TextButton saveToFile;
	TextButton loadFromFile;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ThreadCutterAudioProcessorEditor)
};
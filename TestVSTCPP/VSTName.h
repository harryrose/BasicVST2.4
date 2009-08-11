#pragma once

#include "VST/aeffectx.h"
#include "VST/audioeffectx.h"

/**
 *	Don't forget to do find and replace on all instances of VSTName.
 *	Change the value in setUniqueID('h4ry'); to something unique.
 */
class VSTName;

//Set any numeric constants in here
enum {
	noPrograms = 2,
	noOutputs = 2,
	noInputs = 0,
	noMidiInputs = 1,
	noMidiOutputs = 0,
	noParameters = 0,
	vendorVersion = 1000
};

/**
 * Stores a snapshot of parameters so they can be restored at some point.
 */
class VSTNameProgram
{
	friend class VSTName;

	char name[kVstMaxProgNameLen+1];

	/*
	 * Put your parameters in here
	 */

public:
	VSTNameProgram();
};

/*
 * The actual VST
 */
class VSTName : public AudioEffectX 
{
	private:
		float sampleRate;
		VstInt32 blockSize;
		VSTNameProgram * programs;
		VstInt32 currentDelta;
		
		//Parameters
		
		
	public:
		VSTName(audioMasterCallback callback);
		~VSTName();

		virtual void processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames);

		virtual VstInt32 processEvents (VstEvents* events);

		virtual VstInt32 getProgram();
		virtual void setProgram (VstInt32 program);
		virtual void setProgramName (char* name);
		virtual void getProgramName (char* name);
		virtual bool getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text);

		virtual void setParameter (VstInt32 index, float value);
		virtual float getParameter (VstInt32 index);
		virtual void getParameterLabel (VstInt32 index, char* label);
		virtual void getParameterDisplay (VstInt32 index, char* text);
		virtual void getParameterName (VstInt32 index, char* text);

		virtual void setSampleRate (float sampleRate);
		virtual void setBlockSize (VstInt32 blockSize);

		virtual bool getOutputProperties (VstInt32 index, VstPinProperties* properties);
			
		virtual bool getEffectName (char* name);
		virtual bool getVendorString (char* text);
		virtual bool getProductString (char* text);
		virtual VstInt32 getVendorVersion ();
		virtual VstInt32 canDo (char* text);

		virtual VstInt32 getNumMidiInputChannels ();
		virtual VstInt32 getNumMidiOutputChannels ();

		virtual VstInt32 getMidiProgramName (VstInt32 channel, MidiProgramName* midiProgramName);
		virtual VstInt32 getCurrentMidiProgram (VstInt32 channel, MidiProgramName* currentProgram);
		virtual VstInt32 getMidiProgramCategory (VstInt32 channel, MidiProgramCategory* category);
		virtual bool hasMidiProgramsChanged (VstInt32 channel);
		virtual bool getMidiKeyName (VstInt32 channel, MidiKeyName* keyName);
};


// This is the main DLL file.
#include "VSTName.h"

AudioEffect* createEffectInstance (audioMasterCallback audioMaster)
{
	return new VSTName(audioMaster);
}


//Program
VSTNameProgram::VSTNameProgram()
{
	//default constructor, set everything to default.
	vst_strncpy(this->name,"Woozers",kVstMaxProgNameLen);
}

//The actual VST!!!
VSTName::VSTName(audioMasterCallback callback)
	:AudioEffectX(callback,noPrograms,noParameters)
{
	this->sampleRate = 44100;
	blockSize = 0;
	programs = new VSTNameProgram[noPrograms];

	if(callback)
	{
		setProgram(0);
		setNumInputs(noInputs);
		setNumOutputs(noOutputs);
		//canProcessReplacing();
		//isSynth();
		setUniqueID('h4ry');
	}

}

VSTName::~VSTName()
{
	if(programs)
	{
		delete programs;
	}
}


void VSTName::setProgram (VstInt32 programNo)
{
	if(programNo >= 0 && programNo < noPrograms)
	{
		VSTNameProgram * program = &programs[programNo];
		curProgram = programNo;
	}
}

VstInt32 VSTName::getProgram()
{
	return curProgram;
}

void VSTName::setProgramName (char* name)
{
	vst_strncpy(programs[curProgram].name,name,kVstMaxProgNameLen);
}

void VSTName::getProgramName (char* name)
{
	vst_strncpy(name,programs[curProgram].name,kVstMaxProgNameLen);
}

bool VSTName::getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text)
{
	if(index > 0 && index < noPrograms)
	{
		vst_strncpy(text,programs[index].name,kVstMaxProgNameLen);
	}
	return true;
}

void VSTName::setParameter (VstInt32 index, float value)
{
	switch(index)
	{
	default:
		//
		break;
	}
}
//get the value of the parameter
float VSTName::getParameter (VstInt32 index)
{
	float out = 0;
	switch(index)
	{
	default:
		out = 0;
	}
	return out;
}

void VSTName::getParameterName (VstInt32 index, char* labelout)
{
	char * label;
	switch(index)
	{
	default:
		label = "Cheese";
	}

	vst_strncpy(labelout,label,kVstMaxParamStrLen);
}

void VSTName::getParameterDisplay (VstInt32 index, char* text)
{
	text[0] = '\0';

	switch(index)
	{
	default:
		vst_strncpy(text,"Value",kVstMaxParamStrLen);
	}
}

void VSTName::getParameterLabel(VstInt32 index, char* text)
{
	char * label;
	switch(index)
	{
	default:
		label = "Bleh";
	}

	vst_strncpy(text,label,kVstMaxLabelLen);
}

bool VSTName::getOutputProperties (VstInt32 index, VstPinProperties* properties)
{
	if(index < noOutputs)
	{
		vst_strncpy(properties->label,"Harry",63);//Maybe 63, thats whats in the demo anyway :P
		properties->flags = kVstPinIsActive | kVstPinIsStereo;
		return true;
	}
	return false;
}
	
bool VSTName::getEffectName (char* name)
{
	vst_strncpy(name,"VSTName",kVstMaxEffectNameLen);
	return true;
}

bool VSTName::getVendorString (char* text)
{
	vst_strncpy(text,"VENDORNAME VENDORYEAR",kVstMaxVendorStrLen);
	return true;
}

bool VSTName::getProductString (char* text)
{
	vst_strncpy(text,"VSTName",kVstMaxProductStrLen);
	return true;
}

VstInt32 VSTName::getVendorVersion ()
{
	return vendorVersion;
}

VstInt32 VSTName::canDo (char* text)
{
	//alter this according to what you can do...
	/*if (!strcmp (text, "receiveVstEvents"))
		return 1;
	if (!strcmp (text, "receiveVstMidiEvent"))
		return 1;*/
	return -1;
}

VstInt32 VSTName::getNumMidiInputChannels ()
{
	return noMidiInputs;
}

VstInt32 VSTName::getNumMidiOutputChannels ()
{
	return noMidiOutputs;
}

/**Dont think these need to be implemented for this**/
VstInt32 VSTName::getMidiProgramName (VstInt32 channel, MidiProgramName* midiProgramName)
{
	return 0;
}

VstInt32 VSTName::getCurrentMidiProgram (VstInt32 channel, MidiProgramName* currentProgram)
{
	return 0;
}

VstInt32 VSTName::getMidiProgramCategory (VstInt32 channel, MidiProgramCategory* category)
{
	return 0;
}

bool VSTName::hasMidiProgramsChanged (VstInt32 channel)
{
	return false;
}

bool VSTName::getMidiKeyName (VstInt32 channel, MidiKeyName* keyName)
{
	return false;
}


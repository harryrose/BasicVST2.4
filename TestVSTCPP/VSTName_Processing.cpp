#include "VSTName.h"


void VSTName::processReplacing(float **inputs, float **outputs, VstInt32 sampleFrames)
{

}

VstInt32 VSTName::processEvents (VstEvents* events)
{
	/*for(int i = 0; i < events->numEvents; i++)
	{
		if((events->events[i]->type) != kVstMidiType)
			continue;
		VstMidiEvent * event = (VstMidiEvent*)events->events[i];
		char * midiData = event->midiData;

		VstInt32 status = midiData[0] & 0xf0;
		if(status == 0x90 || status == 0x80)
		{
			VstInt32 note = midiData[1] & 0x7f;
			VstInt32 velocity = midiData[2] & 0x7f;

			if(status == 0x80)
			{
				noteOff();
			}
			else
			{
				noteOn(note,velocity,event->deltaFrames);
			}
		}
		else if(status == 0xb0)
		{
			if (midiData[1] == 0x7e || midiData[1] == 0x7b)
				noteOff();
		}
	}*/
	return 1;
}

void VSTName::setSampleRate (float sampleRate)
{
	this->sampleRate = sampleRate;
	//degreesPerSample = 
}

void VSTName::setBlockSize (VstInt32 blockSize)
{
	this->blockSize = blockSize;
}
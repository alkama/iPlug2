/* ------------------------------------------------------------
name: "FaustExample"
Code generated with Faust 2.11.10 (https://faust.grame.fr)
Compilation options: cpp, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __Distortion_H__
#define  __Distortion_H__


#define FAUSTFLOAT sample

#include "IPlugFaust.h"

/* BEGIN AUTO GENERATED BY THE FAUST COMPILER ... */
#define max std::max
#define min std::min
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


class DistortionSIG0 {
	
  private:
	
	int iRec0[2];
	
  public:
	
	int getNumInputsDistortionSIG0() {
		return 0;
		
	}
	int getNumOutputsDistortionSIG0() {
		return 1;
		
	}
	int getInputRateDistortionSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRateDistortionSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitDistortionSIG0(int samplingFreq) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
			
		}
		
	}
	
	void fillDistortionSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = (iRec0[1] + 1);
			output[i] = std::sin((9.58738019e-05f * float((iRec0[0] + -1))));
			iRec0[1] = iRec0[0];
			
		}
		
	}
};

DistortionSIG0* newDistortionSIG0() { return (DistortionSIG0*)new DistortionSIG0(); }
void deleteDistortionSIG0(DistortionSIG0* dsp) { delete dsp; }

static float ftbl0DistortionSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS Distortion
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class Distortion : public dsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	float fRec1[2];
	float fConst2;
	float fRec2[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "IPlugFaustExample");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "FaustExample");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		DistortionSIG0* sig0 = newDistortionSIG0();
		sig0->instanceInitDistortionSIG0(samplingFreq);
		sig0->fillDistortionSIG0(65536, ftbl0DistortionSIG0);
		deleteDistortionSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (200.0f / fConst0);
		fConst2 = (201.0f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(1.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual Distortion* clone() {
		return new Distortion();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FaustExample");
		ui_interface->addVerticalSlider("Gain", &fVslider0, 1.0f, 0.0f, 1.0f, 0.100000001f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fVslider0);
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec1[0] = (fConst1 + (fRec1[1] - std::floor((fConst1 + fRec1[1]))));
			output0[i] = FAUSTFLOAT((fSlow0 * ftbl0DistortionSIG0[int((65536.0f * fRec1[0]))]));
			fRec2[0] = (fConst2 + (fRec2[1] - std::floor((fConst2 + fRec2[1]))));
			output1[i] = FAUSTFLOAT((fSlow0 * ftbl0DistortionSIG0[int((65536.0f * fRec2[0]))]));
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			
		}
		
	}

	
};
#undef max
#undef min
/* ... END AUTO GENERATED BY THE FAUST COMPILER  */

class Faust_mydsp : public IPlugFaust
{
public:
	Faust_mydsp(const char* name, const char* inputDSPFile = 0, int nVoices = 1, int rate = 1,
						const char* outputCPPFile = 0, const char* drawPath = 0, const char* libraryPath = DEFAULT_FAUST_LIBRARY_PATH)
	: IPlugFaust(name, nVoices)
	{
	}

	void Init() override
	{
		mDSP = new FAUSTCLASS();
		mDSP->buildUserInterface(this);
		BuildParameterMap();
		mInitialized = true;
	}
};

#undef FAUSTCLASS

#endif
#ifndef _CTXNEURON
#define _CTXNEURON

#include <math.h>

class CtxNeuron {

public:
	CtxNeuron(float _learningRate) {
		learningRate = _learningRate;
	}
	
	void addInput(float& anInput, float initWeight = 0) {
		if (nInputs == maxInputs) throw "No more inputs.";
		inputs[nInputs] = &anInput;
		weights[nInputs] = initWeight;
		nInputs++;
	}

	float doStep(float nonPlasticInput, float serot);

private:
	float output;
	float output2;
	static const int maxInputs = 10;
	float* inputs[maxInputs];
	float weights[maxInputs];
	int nInputs = 0;
	float learningRate = 0;
	
	void weightChange(float &w, float delta) {
		w += delta;
		if (w>1) w = 1;
		if (w<0) w = 0;
	}

	float ofc5HTreceptors(float x, float htR1, float htR2) {
		htR1 = 1 + htR1;
		htR2 = 1 + htR2;
		float r = (1-exp(-pow(x/htR1,htR1)))*htR2;
		if (r < 0.00001) return 0;
		return r;
	}

};

#endif


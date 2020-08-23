#include "ctxneuron.h"


CtxNeuron::CtxNeuron(float _learningRate) : 
	learningRate(_learningRate),
	slowCaDetector(new SecondOrderLowpassFilter(0.01))
{
}
	


float CtxNeuron::doStep(float nonPlasticInput, float serot) {
	output = nonPlasticInput;
	for(int i=0;i<nInputs;i++) {
		output += weights[i] * *(inputs[i]);
	}
	// output = output / (float)nInputs * 2;
	if (output < 0) output = 0;
	if (output > 1) output = 1;
	if (serot < 0) serot = 0;
	output = ofc5HTreceptors(output,serot*0.5,serot);
		
	float dOutput = output - output2;
	if (dOutput < 0) dOutput = 0;

	float slowCa = slowCaDetector->filter(output);
	slowCa = fabs(slowCa);

	for(int i=0;i<nInputs;i++) {
		// weight change: LTP
		weightChange(weights[i], learningRate * serot * *(inputs[i]) * dOutput);
		// weight change: LTD
		weightChange(weights[i], - 0.02 * learningRate * slowCa * serot);
	}

	output2 = output;
	return output;
}

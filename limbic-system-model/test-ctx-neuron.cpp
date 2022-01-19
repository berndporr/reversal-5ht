#include <unistd.h>

#include "ctxneuron.h"

int main( int argc, char **argv ) {
	// constants
	float learning_rateLTP = 0.1;
	float learning_rateLTD = 0.00001;
	float tLTD = 0.1;
	float initialWeight = 0.1;
	int nSteps = 10000;

	CtxNeuron ctxNeuron(learning_rateLTP,learning_rateLTD,tLTD);

	// add the plastic input to it
	float filteredPlasticInput = 0;
	ctxNeuron.addInput(filteredPlasticInput,initialWeight);

	// add the static input
	float fixedInput = 0;

	// serotonin
	float serot = 0;

	SecondOrderLowpassFilter inputSmoother(0.1);

	FILE* f = fopen("test-ctx-neuron-result.dat","wt");

	for(int i = 0; i < nSteps; i++) {
		int j = i%1000;

		float plasticInput = 0;
		if ((j > 100) && (j < 200)) {
			plasticInput = 1;
		} else {
			plasticInput = 0;
		}
		filteredPlasticInput = inputSmoother.filter(plasticInput);
		
		if ((j > 190) && (j < 200)) {
			fixedInput = 1;
		} else {
			fixedInput = 0;
		}

		if ((j > 50) && (j < 250)) {
			serot = 1;
		} else {
			serot = 0;
		}

		float act = ctxNeuron.doStep(fixedInput, serot);
		fprintf(f,"%f %f %f %f\n",fixedInput,filteredPlasticInput,serot,act);
	}

	fclose(f);
}


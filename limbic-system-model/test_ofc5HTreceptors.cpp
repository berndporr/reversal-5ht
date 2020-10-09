#include<stdio.h>
#include "ctxneuron.h"

int main( int argc, char **argv ) {
	if (argc < 2) {
		fprintf(stderr,"We need the 5ht conc\n");
		exit(1);
	}
	float serot = atoi(argv[1]);
	FILE* f = fopen("test_5HTrec.dat","wt");
	for(float a = 0; a < 1; a+= 0.01) {
		float act = CtxNeuron::ofc5HTreceptors(a,serot,serot*2);
		fprintf(f,"%f %f\n",a,act);
	}
	fclose(f);
}

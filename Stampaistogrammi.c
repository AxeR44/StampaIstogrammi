#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"include\functions.h"

int main(int argc, char *argv[]){
	int validArg = 0, dimension, *vect, result[RESULTDIM] = {0};
	int intAccumulator1, intAccumulator2;
	float fAccumulator;
	long double lDAccumulator;
	FILE *mFile = NULL;
	char *charAss[][2] = {{"-h","1"},{"-s","2"},{"-ma","3"},{"-mg","4"},{"-mM","5"}, {"-i","6"}};
	if(argc == 1){
		noArgs();
	}
	validArg = matScan(&charAss[0][0], argv, result, argc);
	if (!validArg) {
		argError();
	}if (result[0]) {
		helpFunction();
		exit(0);
	}
	vectorAlloc(&vect, &dimension);
	vectorInit(vect, dimension, mFile);
	for (int i = 1; i < RESULTDIM; i++) {
		if (result[i]) {
			switch (i) {
			case 1:
				vectorSum(vect, &intAccumulator1, dimension);
				printf("La somma e' pari a %d\n", intAccumulator1);
				break;
			case 2:
				//Arithmetic 
				vectorArithmeticMean(vect, &fAccumulator, dimension);
				printf("La media aritmetica e' pari a %f\n", fAccumulator);
				break;
			case 3:
				//Geometric
				/*vectorGeometricMean(vect, &lDAccumulator, dimension);
				printf("La media geometrica e' pari a %lf", lDAccumulator);*/
				printf("Media geometrica N/I\n");
				break;
			case 4:
				//MaxMin
				vectorMaxMin(vect, dimension, &intAccumulator1, &intAccumulator2);
				printf("Il numero massimo presente nel vettore e': %d\nIl numero minimo presente nel vettore e': %d\n\n", intAccumulator1, intAccumulator2);
				break;
			case 5:
				//Isto
				printf("Istogramma N/I\n");
				break;
			}
		}
	}
	free(vect);
	return 0;
}


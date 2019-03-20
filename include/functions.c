#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
#include<time.h>
#include<math.h>
#include<stdint.h>
#include"functions.h"

unsigned int matScan(char** mat, char** argv, int* result, int argc) {
	int offset = 0, trovato = 0, index, nValidArgs = 0;
#ifdef DEBUG
	while (offset < 12) {
		printf("%s\n", *(mat + (offset++)));
	}
#endif // DEBUG	
	for (int i = 1; i < argc; i++) {
		offset = 0;
		while (offset < 12 && (!trovato)) {
			if (!strcmp(argv[i], *(mat + offset))) {
				trovato = 1;
				index = atoi(*(mat + (offset + 1))) - 1;
				result[index] = 1;
				++nValidArgs;
			}
			offset += 2;
		}
		trovato = 0;
	}
#ifdef DEBUG
	for (int i = 0; i < RESULTDIM; i++) {
		printf("%d\t%d\n", i, result[i]);
	}
#endif // DEBUG
	return nValidArgs;
}

void vectorAlloc(int** vect, int* dimension) {
	srand(time(NULL));
	*dimension = rand() + 2001;	//Numero casuale strettamente maggiore di 2000
	*vect = (int*)calloc((*dimension), sizeof(int));
}

void vectorInit(int* vect, int dimension, FILE* mF) {
	int *dummy;
	char buff[BUFFLEN];
	dummy = vect;
	open(&mF, "w");
	for (int i = 0; i < dimension; i++) {
		fprintf(mF, "%d\n", (rand() % 10) + 1);
	}
	fflush(mF);
	reopen(&mF, "r");

#ifdef DEBUG
	printf("%lu", ftell(mF));
#endif // DEBUG

	while (dummy < (vect + dimension)) {
		if (fgets(buff, BUFFLEN, mF) != NULL) {
			sscanf(buff, "%d", dummy);
		}
#ifdef DEBUG
		printf("%d\n", *dummy);
#endif // DEBUG
		++dummy;
	}
	fclose(mF);
}


void vectorSum(int* vector, int* result, int dimension) {
	int* dummy = vector;
	*result = 0;
	while (dummy < (vector + dimension)) {
		(*result) += *dummy;
#ifdef DEBUG
		printf("%d\t%d\n", *dummy, *result);
#endif // DEBUG
		++dummy;
	}
}

//OF
void vectorProduct(int* vector, long double* result, int dimension) {
	int* dummy = vector;
	*result = 1;
	while (dummy < (vector + dimension)) {
		(*result) *= pow((double)(*dummy), (1 / dimension));
		if ((*result) <= 0) {
			printf("PRODOTTO 0\n\n%d\t%lf\n", *dummy, *result);
		}
		else {
			printf("PRODOTTO DIV 0\n\n%d\t%lf\n", *dummy, *result);
		}
		++dummy;
	}
}

void vectorArithmeticMean(int* vector, float* result, int dimension) {
	int sum;
	vectorSum(vector, &sum, dimension);
	*result = (float)sum / dimension;
}

void vectorGeometricMean(int* vector, long double* result, int dimension) {
	long double product;
	vectorProduct(vector, &product, dimension);
	*result = product;
}

void vectorMaxMin(int* vector, int dimension, int* max, int* min) {
	int *dummy = vector;
	if ((*dummy) > *(dummy + 1)) {
		*max = *dummy;
		*min = *(dummy + 1);
	}
	else {
		*min = *dummy;
		*max = *(dummy + 1);
	}
	dummy += 2;
	while (dummy < (vector + dimension)) {
		if ((*dummy) >(*max)) {
			*max = *dummy;
		}
		else if ((*dummy) < (*min)) {
			*min = *dummy;
		}
		++dummy;
	}
}

void open(FILE** mF, char* mode) {
	*mF = fopen("tmp.txt", mode);
	if ((*mF) == NULL) {
		printf("Errore nell'apertura del file");
		exit(0);
	}
}

void reopen(FILE** mF, char* mode) {
	*mF = freopen("tmp.txt", mode, *mF);
	if ((*mF) == NULL) {
		printf("Errore nell'apertura del file");
		exit(0);
	}
}

void helpFunction(void) {
	printf("Stampaistogrammi <argument[s]>:\n\n-s: Somma degli interi nel vettore\n-ma : Media aritmetica\n-mg : Media geometrica\n-mM : Minimo e massimo degli elementi\n-i: Istogramma degli elementi \n\n");
}

void noArgs(void) {
	printf("Nessun argomento inserito: eseguire\n\n\tStampaIstogrammi -h \n\nper visualizzare la lista di argomenti validi\n");
	exit(0);
}

void argError(void) {
	printf("Nessun argomento valido inserito: eseguire\n\n\tStampaIstogrammi -h \n\nper visualizzare la lista di argomenti validi\n");
	exit(0);
}
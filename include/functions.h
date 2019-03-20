#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define DEBUG
#undef DEBUG
#define RESULTDIM 6
#define BUFFLEN 5
#include<stdio.h>
/*
*
*	matScan effettua la scansione del vettore argv passato come secondo parametro e controlla se i parametri inseriti via terminale sono
*	contenuti all'interno della matrice passata per primo parametro. La funzione conserva il risultato i un vettore (il cui puntatore è passato
*	come terzo argomento). Inoltre la Funzione restituisce il numero di parametri validi trovati
*
*/
unsigned int matScan(char**, char**, int*, int);

/*
*
*	vectorAlloc effettua l'allocazione del vettore il cui doppio puntatore è passato come primo argomento, generando inoltre una dimensione
*	casuale conservata nella variabile puntata dal secondo argomento
*
*/
void vectorAlloc(int**, int*);

/*
*
*	vectorInit genera numeri casuali da 1 a 10 scrivendoli su un file (puntatore passato come terzo argomento)
*	Dopodichè la funzione legge i numeri scritti su file e li inserisce all'interno del vettore il cui puntatore
*	è passato come primo argomento
*
*/
void vectorInit(int*, int, FILE*);

/*
*
*	vectorSum calcola la sommatoria di tutti gli elementi nel vettore il cui puntatore è passato come primo argomento:
*	il risultato viene conservato all'interno della variabile puntata dal secondo argomento
*
*/
void vectorSum(int*, int*, int);

/*
*
*	vectorProduct calcola la produttoria di tutti gli elementi nel vettore il cui puntatore è passato come primo argomento:
*	il risultato viene conservato all'interno della variabile puntata dal secondo argomento
*
*/
void vectorProduct(int*, long double*, int);

/*
*
*	vectorArithmeticMean calcola la media aritmetica di tutti gli elementi nel vettore il cui puntatore è passato come primo argomento:
*	il risultato viene conservato all'interno della variabile puntata dal secondo argomento
*
*/
void vectorArithmeticMean(int*, float*, int);

/*
*
*	vectorGeometricMean calcola la media ggeometrica di tutti gli elementi nel vettore il cui puntatore è passato come primo argomento:
*	il risultato viene conservato all'interno della variabile puntata dal secondo argomento
*
*/
void vectorGeometricMean(int*, long double*, int);

/*
*
*	vectorMaxMin calcola il massimo e il minimo tra tutti gli elementi contenuti nel vettore il cui puntatore è passato come primo argomento:
*	il massimo e il minimo vengono rispettivamente conservati all'interno delle variabili puntate dal terzo e quarto parametro
*
*/
void vectorMaxMin(int*, int, int*, int*);

/*
*
*	open è una funzione helper che controlla se il FILE viene aperto correttamente: in caso contrario il programma viene terminato
*
*/
void open(FILE**, char*);

/*
*
*	reopen è una funzione helper che controlla se il FILE viene riaperto correttamente: in caso contrario il programma viene terminato
*
*/
void reopen(FILE**, char*);

/*
*
*	helpFunction stampa a schermo il menù delle opzioni valide terminando subito dopo il programma
*
*/
void helpFunction(void);

/*
*
*	argError stampa a schermo un errore nel caso in cui non fosse stato inserito almeno un argomento valido
*
*/
void argError(void);

/*
*
*	noArgs stampa a schermo un errore nel caso in cui non fosse stato inserito nemmeno un argomento
*
*/
void noArgs(void);
#endif
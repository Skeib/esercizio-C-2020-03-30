#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stddef.h>

/*

 * *** esercizio 2020-03-30*** (deve risultare un unico programma in C, scrivete tutto il codice sorgente in src/esercizio20200330.c)

A - scrivere la seguente funzione:

implementare una funzione che calcola la serie di Fibonacci:

unsigned long fibonacci(unsigned int n);

dove:
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)  per n > 1

provare a scoprire quale è il valore massimo di n per cui fibonacci(n) restituisce un valore della serie corretto


B - scrivere la seguente funzione:

unsigned long * fibonacci_array(unsigned int n);

questa funzione restituisce un array di unsigned long di dimensione n+1 (n è l'argomento della funzione)
dove la cella i-ma contiene il valore di fibonacci(i).


C - main() fa queste operazioni:

calcola fibonacci_array(39) e lo assegna alla varibile 'fibonacci_result'  // fibonacci(39) = 63245986

fare una copia dell'array fibonacci_result in 'fibonacci_result_copy' (i due array devono avere aree di memoria distinte)

fibonacci_result_copy: fare il 'reverse' dell'array ('copiare' da esempio 004.1arrays-operations)

su fibonacci_result_copy: applicare bubble_sort ('copiare' da esempio 004.1arrays-operations)

confrontare fibonacci_result e fibonacci_result_copy, verificare che i due array siano uguali (scrivere su stdout il risultato).
 */

unsigned long fibonacci(unsigned int n){

	unsigned long fn =0;
	unsigned long fn_1 = 1;
	unsigned long fn_2 = 0;

	for(int i=0; i<n; i++){

		if(i==0)
			fn = 0;
		if(i==1)
			fn=1;
		else{

		fn = (fn_1 + fn_2);

		fn_2 = fn_1;
		fn_1 = fn;
		}
	}

	return fn;

}

unsigned long * fibonacci_array(unsigned int n){

	unsigned long * array;

	array = calloc(n+1, sizeof(unsigned long));

	for(int i=0; i<=n; i++){

		array[i] = fibonacci(i);

	}

	return array;

}


void swap_int(unsigned long *x, unsigned long *y) {
	int t = *x;
	*x = *y;
	*y = t;
}
unsigned long * reverse_int(unsigned long * array, unsigned int i, unsigned int j)
{
	while (i < j)
		swap_int(&array[i++], &array[--j]);

	return array;
}

unsigned long * complete_reverse_int(unsigned long * array, unsigned int array_len) {
	return reverse_int(array, 0, array_len);
}

void bubble_sort(unsigned long * array, unsigned int caselle_array) {

	int count = 0;

	for(int i=1; i<caselle_array; i++){
	if(array[i-1]>array[i]){
			swap_int(&array[i-1], &array[i]);
			count++;
	}
	if(i == caselle_array-1 && count>0){
		count =0;
		i=0;
	}

}
}

int main(){

	unsigned int num = 40;

	unsigned long * fibonacci_result = fibonacci_array(num-1);	// fibonacci(39) = 63245986

	unsigned long * fibonacci_result_copy;


	fibonacci_result_copy = calloc(num, sizeof(unsigned long));

	//sizeof(fibonacci_result) pesa sempre 8 byte perché è un indirizzo



	memcpy(fibonacci_result_copy, fibonacci_result, num*sizeof(unsigned long));

	fibonacci_result_copy = complete_reverse_int(fibonacci_result_copy, num);

	bubble_sort(fibonacci_result_copy, num);

	int unic = memcmp(fibonacci_result, fibonacci_result_copy, num);

	if(unic == 0){
		printf("\ni due array\n");

				for(int i=0; i< num; i++)
						printf("%lu ", fibonacci_result[i]);

				printf("\ne\n");

				for(int i=0; i< num; i++)
						printf("%lu ", fibonacci_result_copy[i]);

				printf("\nsono uguali!");
	}

	else{
		printf("\ni due array\n");

		for(int i=0; i< num; i++)
				printf("%lu ", fibonacci_result[i]);

		printf("\ne\n");

		for(int i=0; i< num; i++)
				printf("%lu ", fibonacci_result_copy[i]);

		printf("\nsono diversi!");
	}

	free(fibonacci_result_copy);

	free(fibonacci_result);

	return 0;

}






















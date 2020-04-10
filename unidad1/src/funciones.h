#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "tipos.h"

vector<int> buscar_impar(vector<int> v); //O(nlogn)
int buscar_impar_optimal(vector<int> v); //O(n)


int calcular_pentagono_optimo(int n); //O(1)
int calcular_pentagono_recursiva(int n);

void printArray(int* data, int n);

/*
 * data = [1 2 5 7 3 7]
 */
void quickSortRec(int* data, int l, int h);
void quickSortIter(int* data, int l, int h);



#endif //FUNCIONES_H

#include "funciones.h"

/*
 * 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5
 * O(nlogn) + O(n) = O(nlogn) time
 * O(n) space
 */
vector<int> buscar_impar(vector<int> v) {
    vector<int> res;
    sort(v.begin(), v.end()); //O(nlogn)
    /*
     * -2, -2, -1, 1, 1, 2, 2, 4, 4, 5, 5
     * res = empty
     * res = -2
     * res = empty
     * res = -1
     * res = -1 1
     * res = -1
     * res = -1 2
     * res = -1
     * res = -1 4
     * res = -1
     * res = -1 5
     * res = -1
     */
    for (auto item: v) {
        if (!res.empty() && res.back() == item)
            res.pop_back();
        else
            res.push_back(item);
    }
    return res;
}

/*
 * O(n) time
 * O(n) space
 */
int  buscar_impar_optimal(vector<int> v) {
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++) {
        m[v.at(i)]++;
    }

    /*for (auto x : m) {
        cout<<x.first<<" - "<<x.second<<endl;
    }*/

    int impar_key = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second%2 != 0)
            impar_key = it->first;
    }
    return impar_key;
}

/*
 * 1  6  16  31  ....  141
 *  5  10  15  ...
 *    5  5   5 ...
 *
 *    an^2 + bn + c
 *    2a = 5 => a= 5/2
 *    3a + b = 6-1
 *         b= -5/2
 *
 *    a + b + c = 1
 *        c = 1
 *    5/2*n^2 -5/2n + 1
 * O(1) time
 */
int calcular_pentagono_optimo(int n) {
    return (5*pow(n, 2))/2 -(5*n)/2 + 1;
}

/*
 * O(n^2)
 */
int calcular_pentagono_recursiva(int n) {
    if (n == 0) return 1;
    return calcular_pentagono_recursiva(n-1) + 5*n;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * O(n) time
 * O(1) space
 */
int partitionHoare(int* data, int l, int h) {
    int i = l-1, j = h+1;
    int pivot = data[l];
    while (true) {
        do {
            i++;
        } while (data[i] < pivot);
        do {
            j--;
        } while (data[j] > pivot);
        if (j <= i) return j;
        swap(data[i], data[j]);
    }
}

/*
 * 1, 5, 2, 9, 10
 * 1  2  5  9  10
 * p = 2
 * l = 0
 * h = 4
 *
 * O(nlogn) time
 * O(logn) space
 */
void quickSortRec(int* data, int l, int h) {
    if (l < h) {
        int p = partitionHoare(data, l, h);
        quickSortRec(data, l, p);
        quickSortRec(data, p+1, h);
    }
}

/*
 * O(n) tume
 * O(1) space
 */
int partitionLomuto(int* data, int l, int h) {
    int pivot = data[h];
    int i = l-1;
    for (int j = l; j <= h-1; j++) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i+1], data[h]);
    return i+1;
}

/*
 * O(n) time
 * O(n) space
 */
void quickSortIter(int* data, int l, int h) {
    int* stack = new int[h-l+1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partitionLomuto(data, l, h);

        if (p-1 > l) {
            stack[++top] = l;
            stack[++top] = p-1;
        }

        if (p+1 < h) {
            stack[++top] = p+1;
            stack[++top] = h;
        }
    }
    delete [] stack;
}
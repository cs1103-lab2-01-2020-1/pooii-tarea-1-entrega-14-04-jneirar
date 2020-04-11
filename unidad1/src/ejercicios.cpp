#include "ejercicios.h"
#include "funciones.h"
#include "clases/quicksort_t.h"
#include "clases/quicksort2_t.h"
#include "clases/quicksort2_t.cpp"
#include "clases/Integer.h"
//#include "clases/Integer.cpp"
#include "clases/Number.h"
#include "clases/Number.cpp"
#include "clases/vector.h"

void ejercicio1() {

    cout<<"buscar_impar"<<endl;
    for(auto x : buscar_impar({1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}))
        cout<<x<<endl;

    for (auto x: buscar_impar({20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}))
        cout<<x<<endl;

    for (auto x: buscar_impar({10}))
        cout<<x<<endl;

    cout<<"buscar_impar optimo"<<endl;

    cout<<buscar_impar_optimal({1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5})<<endl;
    cout<<buscar_impar_optimal({20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5})<<endl;
    cout<<buscar_impar_optimal({10})<<endl;
}


void ejercicio2() {
    cout<<"recursiva"<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<(i+1)<<" - "<<calcular_pentagono_recursiva(i)<<endl;
    }

    cout<<"optima"<<endl;
    for (int i = 1; i < 9; i++) {
        cout<<(i)<<" - "<<calcular_pentagono_optimo(i)<<endl;
    }
}

void ejercicio3a() {
    cout<<"quickSort recursivo"<<endl;
    string input = "in.txt";
    string output = "out.txt";
    ifstream myfile(input);
    if (myfile.is_open()) {
        int N, index = 0;
        myfile>>N;
        int* data = new int[N]{};
        while(N--) {
            int n;
            myfile>>n;
            data[index] = n;
            index++;
        }
        N = index;
        cout<<"print no sorting"<<endl;
        printArray(data, N);
        quickSortRec(data, 0, N-1);
        cout<<"print sorted array"<<endl;
        printArray(data, N);

        ofstream out(output);
        for (int i = 0; i < N; i++)
            out<<data[i]<<" ";
        out.close();
        myfile.close();
        delete [] data;
    }

    cout<<"quickSort iterativo"<<endl;
    int n = 10;
    int* data = new int[n]{10, 7, 5, 6, 8, 11, 25, 63, 41, 69};
    cout<<"print no sorting"<<endl;
    printArray(data, n);
    quickSortIter(data, 0, n-1);
    cout<<"print sorted array"<<endl;
    printArray(data, n);
}


void printArray(int* data, int n) {
    for(int i =0; i < n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void ejercicio3b() {
    quicksort_t qs;
    qs<<"in.txt";
    qs>>"out2.txt";
}

void ejercicio4() {
    quicksort2_t<int> qs;
    qs<<"in.txt";
    qs>>"out3.txt";
    quicksort2_t<string> qsstring;
    qsstring<<"instring.txt";
    qsstring>>"out4.txt";
}

void ejercicio5a(){
    cout << "Clase Integer generada" << endl;
    Integer A1;
    cout << "\tCreating A1(): " << A1 << endl;
    A1 = 2;
    cout << "\tA1 = 2: " << A1 << endl;
    A1 *= 4;
    cout << "\tA1 *= 4: " << A1 << endl;
    cout << "\tA1 ^ 3: " << (A1^3) << endl;
    Integer A2(4);
    cout << "\tA1=8 y A2(4). A1 > A2: " << (A1>A2) << endl;
    cout << "\tA1=8 y A2(4). A1 == A2: " << (A1==A2) << endl;
}

void ejercicio5b(){
    cout << "Clase Number generada" << endl;
    Number<int> A1;
    cout << "\tCreating integer A1(): " << A1 << endl;
    A1 = 2;
    cout << "\tA1 = 2: " << A1 << endl;
    A1 *= 4;
    cout << "\tA1 *= 4: " << A1 << endl;
    cout << "\tA1 ^ 3: " << (A1^3) << endl;
    Number<float> A2(2.5);
    cout << "\tCreating float A2(): " << A2 << endl;
    cout << "\tA2 ^ 3: " << (A2^3) << endl;
}

void ejercicio6(){
    cout << "Clase UTEC::vector creada" << endl;

    UTEC::vector V1;
    V1.push_back(2);
    V1.push_back(3);
    V1.push_back(4);
    cout << "\n\tCreating V1: ";
    V1.imprime();

    V1.push_back(3);
    cout << "\n\tPush_back(3): ";
    V1.imprime();

    V1.pop_back();
    cout << "\n\tPop_back(): ";
    V1.imprime();

    UTEC::vector V2;
    V2 = V1;
    cout << "\n\tCreating V2 = V1: ";
    cout << "\n\tV1: ";
    V1.imprime();
    cout << "\tV2: ";
    V2.imprime();

    V2.insert(2, 20);
    cout << "\n\tInsert 20 in pos 2 in V2: ";
    cout << "\n\tV1: ";
    V1.imprime();
    cout << "\tV2: ";
    V2.imprime();

    V1.erase(1);
    cout << "\n\tErase pos 1 in V1: ";
    cout << "\n\tV1: ";
    V1.imprime();
    cout << "\tV2: ";
    V2.imprime();

    UTEC::vector V3;
    V3 = V1 + V2;
    cout << "\n\tCreating V3 = V1 + V2: ";
    V3.imprime();
}
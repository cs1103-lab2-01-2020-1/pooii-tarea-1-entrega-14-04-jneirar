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
    cout << "En todos los ejemplos se usa cout << Integer" << endl;

    cout << "TEST CONSTRUCTORS:" << endl;

    Integer A1;
    cout << "\tCreating A1 vacío Integer A1: " << A1 << endl;

    Integer A(1);
    cout << "\tCreating A with initial value Integer A(1): " << A << endl;

    Integer B = A;
    cout << "\tCreating B with copy constructor with A Integer B=A: " << "A = " << A << ", B = " << B << endl;

    cout << "TEST ASSIGNMENT - CAST:" << endl;

    A1 = 2;
    cout << "\tA1 = 2: " << A1 << endl;

    float floatVar = 2.5;
    B = (int) floatVar;
    cout << "\tfloat floatVar = 2.5; B = (int) floatVar: " << B << endl;

    cout << "TEST MATH OPERATIONS: A = 2, B = 5" << endl;
    A = 2;
    B = 5;
    Integer C;

    C = A ^ 2; //A = 2, B = 5
    cout <<  "\tC = A ^ 2: " << C << endl;
    C = A ^ 10; //A = 2, B = 5
    cout <<  "\tC = A ^ 10: " << C << endl;

    C = A + B; //A = 2, B = 5
    cout <<  "\tC = A + B: " << C << endl;

    C = B - A; //A = 2, B = 5
    cout <<  "\tC = B - A: " << C << endl;

    C = A * B; //A = 2, B = 5
    cout <<  "\tC = A * B: " << C << endl;

    C = B / A; //A = 2, B = 5
    cout <<  "\tC = B / A: " << C << endl;

    A += 6; //A = 8
    cout <<  "\tA += 6: " << A << endl;

    A -= 5; //A = 3
    cout <<  "\tA -= 5: " << A << endl;

    A *= 7; //A = 21
    cout <<  "\tA *= 7: " << A << endl;

    A /= 3; //A = 7
    cout <<  "\tA /= 3: " << A << endl;

    cout << "TEST COMPARE OPERATIONS: A = 6, B = 4, C = 6" << endl;
    A = 6; B = 4; C = 6;

    cout << "\tA > B: " << (A > B) << endl;
    cout << "\tB > C: " << (B > C) << endl;
    cout << "\tA < C: " << (A < C) << endl;
    cout << "\tB < C: " << (B < C) << endl;
    cout << "\tA == B: " << (A == B) << endl;
    cout << "\tA == C: " << (A == C) << endl;
    cout << "\tA != B: " << (A != B) << endl;
    cout << "\tA != C: " << (A != C) << endl;

    cout << "TEST IN-OUT" << endl;
    cout << "\tInsert a number: ";
    cin >> A;
    cout << "\tInteger A is: " << A << endl;
}

void ejercicio5b(){
    cout << "Clase Number generada" << endl;
    cout << "Test the same examples from exercise 5a with float numbers" << endl;

    cout << "TEST CONSTRUCTORS:" << endl;

    Number<float> A1;
    cout << "\tCreating A1 vacío Number<float> A1: " << A1 << endl;

    Number<float> A(1.5);
    cout << "\tCreating A with initial value Integer Number<float> A(1.5): " << A << endl;

    Number<float> B = A;
    cout << "\tCreating B with copy constructor with A Number<float> B = A: " << "A = " << A << ", B = " << B << endl;

    cout << "TEST ASSIGNMENT - CAST:" << endl;

    A1 = 2.5;
    cout << "\tA1 = 2.5: " << A1 << endl;

    int numInt = 5;
    B = (float) numInt;
    cout << "\tint numInt = 5; B = (float) numInt: " << B << endl;

    cout << "TEST MATH OPERATIONS: A = 2.5, B = 3.8" << endl;
    A = 2.5;
    B = 3.8;
    Number<float> C;

    C = A ^ 2; //A = 2.5 B = 3.8
    cout <<  "\tC = A ^ 2: " << C << endl;
    C = A ^ 10; //A = 2.5 B = 3.8
    cout <<  "\tC = A ^ 10: " << C << endl;

    C = A + B; //A = 2.5 B = 3.8
    cout <<  "\tC = A + B: " << C << endl;

    C = B - A; //A = 2.5 B = 3.8
    cout <<  "\tC = B - A: " << C << endl;

    C = A * B; //A = 2.5 B = 3.8
    cout <<  "\tC = A * B: " << C << endl;

    C = B / A; //A = 2.5 B = 3.8
    cout <<  "\tC = B / A: " << C << endl;

    A += 6; //A = 8.5
    cout <<  "\tA += 6: " << A << endl;

    A -= 4; //A = 4.5
    cout <<  "\tA -= 4: " << A << endl;

    A *= 2; //A = 9
    cout <<  "\tA *= 2: " << A << endl;

    A /= 5; //A = 1.8
    cout <<  "\tA /= 5: " << A << endl;

    cout << "TEST COMPARE OPERATIONS: A = 1.7, B = 2.5, C = 1.7" << endl;
    A = 1.7; B = 2.5; C = 1.7;

    cout << "\tA > B: " << (A > B) << endl;
    cout << "\tB > C: " << (B > C) << endl;
    cout << "\tA < C: " << (A < C) << endl;
    cout << "\tB < C: " << (B < C) << endl;
    cout << "\tA == B: " << (A == B) << endl;
    cout << "\tA == C: " << (A == C) << endl;
    cout << "\tA != B: " << (A != B) << endl;
    cout << "\tA != C: " << (A != C) << endl;

    cout << "TEST IN-OUT" << endl;
    cout << "\tInsert a FLOAT number: ";
    cin >> A;
    cout << "\tA is: " << A << endl;
}

void ejercicio6(){
    cout << "Clase UTEC::vector creada" << endl;
    cout << "Use print function to print the vector with size and capacity" << endl;
    cout << "\n\tCreating UTEC::vector V1 and insert 2, 3, 4 with pushback: ";
    UTEC::vector V1;
    V1.push_back(2);
    V1.push_back(3);
    V1.push_back(4);
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

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    UTEC::vector V4(arr, 10);
    cout << "\n\tCreating V4. arr is an array. UTEC::vector V4(arr, 10): ";
    V4.imprime();
}
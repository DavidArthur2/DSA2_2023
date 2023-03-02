#include <iostream>
#include <fstream>
#include "Rekurzio_Functions.h"
using namespace std;

int *initializeArray(int numberOfElements){
    int *t=new int[numberOfElements];

}
void readArray(int *&array, int & numberOfElements, char
input[20]){
    ifstream be(input);

    int tmp;
    be >> tmp;
    int i=0;
    while(be>>array[i++]);
    be.close();

}
void printArray(int *array, int numberOfElements){
    for(int i=0;i<numberOfElements;i++)
        cout << array[i] << ' ';
    cout << endl;
}
void printReverseArray(int *array, int numberOfElements){
    for(int i=numberOfElements-1;i>=0;i--)
        cout << array[i] << ' ';
    cout << endl;
}
int **initializeMatrix(int numberOfRows, int numberOfColumns){
    int **t=new int*[numberOfRows];
    for(int i=0;i<numberOfRows;i++)
        t[i]=new int[numberOfColumns];



    return t;
}
void readMatrix(int **&matrix, int & numberOfRows, int &
numberOfColumns, char input[20]){
    ifstream be(input);
    be >> numberOfRows >> numberOfColumns;
    for(int i=0;i<numberOfRows;i++)
        for(int j=0;j<numberOfColumns;j++)
            be>>matrix[i][j];
    be.close();
}
void printMatrix(int **matrix, int numberOfRows, int
numberOfColumns){
    for(int i=0;i<numberOfRows;i++)
    {
        for(int j=0;j<numberOfColumns;j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}
int main() {
    /*
    int n;
    int *t;
    ifstream be("be.txt");
    be>>n;
    be.close();
    t= initializeArray(n);
    readArray(t,n,"be.txt");
    printArray(t,n);
    printReverseArray(t,n);
    return 0;

    int n,m;
    int **t;
    ifstream be("be.txt");
    be >> n >> m;
    be.close();
    t=initializeMatrix(n,m);
    readMatrix(t,n,m,"be.txt");
    printMatrix(t,n,m);
    */
    //printDigitsOfNumberReverse(1234);
    printf("%0.1f",averageDigitsOfNumber(1234,0,0));
}

#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;


int main(){
    int rowsA, colsA, rowsB, colsB;

    //input matrix A and dimension
    cout << "Enter amount of rows for matrix A: ";
    cin >> rowsA;
    cout << "\nEnter amount of colums for matrix A: ";
    cin >> colsA;

    //input matrix B and dimension
    cout << "\nEnter amount of rows for matrix B: ";
    cin >> rowsB;
    cout << "\nEnter amount of colums for matrix B: " ; 
    cin >> colsB;

    if (colsA != rowsB){
        cout << "\nThe matrix does not match, can't perform multiplication" << endl ;
        return 1;
    }
    //input matrix A
    vector<vector<double> > matrixA(rowsA, vector<double>(colsA));
    cout << "\nEnter the elements for matrix A: " <<endl;
    for (int i =0; i < rowsA; ++i){
        for(int j = 0; j < colsA; ++j){
            cin >> matrixA[i][j];
        }
    }
    cout <<"Matrix A is: " << endl;
    printMatrix(matrixA);
    //input matrix B
    vector<vector<double> > matrixB(rowsB, vector<double>(colsB));
    cout << "Enter the elements for matrix B: " <<endl;
    for (int i =0; i < rowsB; ++i){
        for(int j = 0; j < colsB; ++j){
            cin >> matrixB[i][j];
        }
    }

    cout <<"Matrix B is: " << endl;
    printMatrix(matrixB);

    //Perform matrix multiplication
    vector<vector<double> > resultMultiplication(rowsA, vector<double>(colsB));
    for(int i = 0; i < rowsA; ++i){
        for (int j = 0; j < colsB; ++j){
            for (int k = 0; k < colsA; ++k){
                resultMultiplication[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Matrix A * Matrix B:" <<endl;
    printMatrix(resultMultiplication);
    cout << endl;

    //Flatten the multiplication result into 1d array for bubble sort
    vector<double> flattenMultiplication;
    for (int i = 0; i < rowsA; ++i){
        for (int j = 0; j < colsB; ++j){
            flattenMultiplication.push_back(resultMultiplication[i][j]);
        }
    }

    //Sort flatten array in ascending order
    bubbleSort(flattenMultiplication, true);
    cout << "Sorted Matrix A * Maxtrix B (Ascending order):" << endl;

    //reconstruct the sorted multiplication result back into matrix form
    vector<vector<double> > sortedMultiplication(rowsA, vector<double>(colsB));
    int k1 = 0;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            sortedMultiplication[i][j] = flattenMultiplication[k1];
            k1++;
            }
        }
    // Print the sorted matrix
    printMatrix(sortedMultiplication);
    cout << endl;

    vector<vector<double> > resultDivison(rowsA, vector<double>(colsB));
    for(int i = 0; i < rowsA; ++i){
        for (int j = 0; j < colsB; ++j){
            for (int k = 0; k < colsA; ++k){
                resultDivison[i][j] += matrixA[i][k] / matrixB[k][j];
            }
        }
    }
    cout << "Matrix A / Matrix B:" <<endl;
    printMatrix(resultDivison);
    cout << endl;

    vector<double> flattenDivision;
    for (int i = 0; i < rowsA; ++i){
        for (int j = 0; j < colsB; ++j){
            flattenDivision.push_back(resultDivison[i][j]);
        }   
    }
    //Sort flatten array in descending order
    bubbleSort(flattenDivision, false);
    cout << "Sorted Matrix A / Maxtrix B (Descending order):" << endl;

    //reconstruct the sorted multiplication result back into matrix form
    vector<vector<double> > sortedDivision(rowsA, vector<double>(colsB));
    int k2 = 0;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            sortedDivision[i][j] = flattenDivision[k2];
            k2++;
            }
        }
    printMatrix(sortedDivision);
    cout << endl;
}

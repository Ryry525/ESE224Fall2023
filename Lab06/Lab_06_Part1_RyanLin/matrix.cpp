#include "matrix.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void bubbleSort(vector<double>& arr, bool ascending)
{
    int i, j;
    bool swapped;
    if(ascending ==1){
        for (i=0; i<arr.size() - 1; i++){
            swapped = false;
            for(j=0; j<arr.size()- i - 1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped = true;
                }
            }
            if (swapped == false)
            break;
        }
    }
    else{
        for (i=0; i <arr.size() - 1; i++){
            swapped = false;
            for(j=0; j<arr.size() - i - 1; j++){
                if(arr[j] < arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (swapped == false)
            break;
        }
    }
}

vector<vector<double> > transposeMatrix(vector<vector<double> > matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

     // Create a new matrix to store the transpose
    vector<vector<double> > transposed(cols, vector<double>(rows,0));
     // Transpose the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

void printMatrix(vector<vector<double> >& matrix){
    for (vector<double> row : matrix){
        for (double num : row){
            cout << setprecision(3) << num << " ";
        }
        cout << endl;
    }
}
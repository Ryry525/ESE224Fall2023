#include <iostream>
#include <algorithm>

using namespace std;

bool isSorted(int* arr, int size);
void bubbleSort(int* arr, int size);

int main(){
    int n; 
    cout << "Enter the amount of numbers in array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "\nEnter " << n << " integer values:" <<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (isSorted(arr, n)) {
        cout << "The array is already sorted in ascending order." << endl;
    } else {
        cout << "The array is not sorted. Sorting it now..." << endl;
        bubbleSort(arr, n);
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    delete[] arr;
    return 0;

}

bool isSorted(int* arr, int size){
    for(int i = 1; i < size; i++)
    {
        if(arr[i-1] > arr[i])
            return false;
    }
    return true;
}
void bubbleSort(int* arr, int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1],arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}
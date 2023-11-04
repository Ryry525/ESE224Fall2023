#include <iostream>
#include <vector>
#include "matrix_product.h"

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int> > nums(rows, vector<int>(cols));

    cout << "Input the values of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> nums[i][j];
        }
    }
     vector<int> result = rowProduct(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    int maxSubarrayProduct = maxProduct(result);

    cout << "Maximum product of a subarray: " << maxSubarrayProduct << endl;
    return 0;
}
    
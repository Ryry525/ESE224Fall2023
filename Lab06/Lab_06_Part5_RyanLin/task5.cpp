#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> nums(rows, vector<int>(cols));

    cout << "Enter the elements row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> nums[i][j];
        }
    }
    
#include <iostream>
#include <vector>

using namespace std;

vector<int> createMatrixAndGetSpiralOrder(vector<vector<int> > &matrix);

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;


    // populate the 2d matrix
    vector<vector<int> > matrix;
    int count  = 1;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(count++);
        }
        matrix.push_back(temp);
    }
vector<int> result = createMatrixAndGetSpiralOrder(matrix);

    cout << "\nSpiral Order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

vector<int> createMatrixAndGetSpiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;

    // Extract the elements in the desired spiral order
    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
    int direction =0;
    while (top <= bottom && left <= right) {
        // Traverse from top to bottom
        if(direction == 0){
            // Traverse from left to right
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        direction = 1;
        }
        else if (direction == 1){
            // Traverse from bottom to top
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        direction = 2;
        }
        else if(direction == 2){
        // Traverse from right to left
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            direction =3;
        }
        else if (direction == 3){
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][left]);
        }
        left++;
        direction =0;
        }
    }

    return result;
}

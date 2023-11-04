#include "matrix_product.h"

using namespace std;

vector<int> rowProduct(vector<vector<int> >& nums) {
    vector<int> productRow;
    int rows = nums.size();
    int cols = nums[0].size();

    for (int i = 0; i < rows; i++) {
        int product = 1;
        for (int j = 0; j < cols; j++) {
            product *= nums[i][j];
        }
        productRow.push_back(product);
    }

    return productRow;
}
int maxProduct(vector<int>& nums) {
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(nums[i], maxProduct * nums[i]);
        minProduct = min(nums[i], minProduct * nums[i]);

        result = max(result, maxProduct);
    }

    return result;
}
#include <iostream>
#include <vector>
#include <algorithm>

#define NUM_MAX 10000

using namespace std;

int maxSubArrayLength(vector<int>& nums, int k);

int main() {
    int k;
    vector<int> nums;
    int num;

    cout << "Enter the numbers (Enter -1 to stop): ";

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        if (num > NUM_MAX) {
            cout << "The number is too big. Please enter a smaller number." << endl;
        } else {
            nums.push_back(num);
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > NUM_MAX) {
        cout << "The value of k is too big." << endl;
        return 1; // You might want to return a non-zero value to indicate an error.
    }

    int result = maxSubArrayLength(nums, k);
    cout << "Maximum length: " << result << endl;

    return 0;
}

int maxSubArrayLength(vector<int>& nums, int k) {
    int maxLen = 0;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum > k) {
            sum -= nums[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

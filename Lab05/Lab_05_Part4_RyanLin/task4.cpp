#include <iostream>
#include <vector>
using namespace std;

int position(vector<int>& nums, int target);

int main(){
    vector<int> sortedArray;
    
    int target;
    string input;
    cout << "Enter the value of the sorted Array one by one(finish by typing done): ";
    while (true) {
    cin >> input;
    if (input == "done") {
            break;
        }
    int num = stoi(input);
    sortedArray.push_back(num); 
    }
    cout << "\nEnter a target value: ";
    cin >> target;

    int getPosition = position(sortedArray, target);
    cout << "The target value " << target << " should be inserted at index " << getPosition << "." << endl;
}


int position(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
#include <iostream>
#include <vector>
using namespace std;

/*
take this test case :
  Input: [2, 1, 5, 6]
  Target sum: 9 
  Output: [2, 1, 6]
*/

// --- Function to find a sublist (subset) whose sum equals target ---
bool backtrack(int index, vector<int>& nums, vector<int>& current, int total, int target, vector<int>& result) {
    // Base case: found target sum
    if (total == target) {
        result = current; // store the found subset
        return true;
    }

    // Base case: reached end of list
    if (index >= nums.size()) {
        return false;
    }

    // Include current number
    current.push_back(nums[index]);
    if (backtrack(index + 1, nums, current, total + nums[index], target, result))
        return true;
    current.pop_back();  // backtrack (remove last added element)

    // Exclude current number
    if (backtrack(index + 1, nums, current, total, target, result))
        return true;

    return false;
}

// --- Wrapper function ---
vector<int> findSublistSum(vector<int>& nums, int target) {
    vector<int> result;
    vector<int> current;
    backtrack(0, nums, current, 0, target, result);
    return result;
}

// --- Main function ---
int main() {
    vector<int> nums = {2, 1, 5, 6};
    int target = 9;

    vector<int> result = findSublistSum(nums, target);

    if (!result.empty()) {
        cout << "Sublist with target sum: ";
        cout<< "{"<<" ";
        for (int x : result)
            cout << x << ",";
        cout<<"}"<<" ";
        cout << endl;
    } else {
        cout << "No sublist found." << endl;
    }

    return 0;
}

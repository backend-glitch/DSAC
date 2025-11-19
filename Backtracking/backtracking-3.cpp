#include <bits/stdc++.h>
using namespace std;


void getperm(vector<int> &nums, int index, vector<vector<int>> &ans) {

    // base case
    if (index == nums.size()) {
        ans.push_back(nums);  // store the permutation
        return;
    }

    for (int i = index; i < nums.size(); i++) {

        // include case
        swap(nums[index], nums[i]);

        getperm(nums, index + 1, ans);

        // backtracking
        swap(nums[index], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};   // example input
    vector<vector<int>> ans;

    getperm(nums, 0, ans);

    // print all permutations
    cout << "All permutations:\n";
    for (auto &perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// recursion function
void getallsubsets(vector<int> nums, vector<int> ans, int i, vector<vector<int>>& allsubsets) {

    // base case
    if (i == nums.size()) {
        allsubsets.push_back(ans);
        return;
    }

    // include current element
    ans.push_back(nums[i]);
    getallsubsets(nums, ans, i + 1, allsubsets);

    // backtracking
    ans.pop_back();

    // exclude current element
    getallsubsets(nums, ans, i + 1, allsubsets);
}

// main subsets function
vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> allsubsets;
    vector<int> ans;

    sort(nums.begin(), nums.end());

    getallsubsets(nums, ans, 0, allsubsets);

    return allsubsets;
}

int main() {
    
    vector<int>nums = {1,2,3};

    vector<vector<int>> result = subsets(nums);

    cout << "\nAll Subsets:\n";
    for (auto &subset : result) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}

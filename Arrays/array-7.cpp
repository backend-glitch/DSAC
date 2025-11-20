#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> ans(n);

    // Build prefix array
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Build suffix array
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Multiply prefix and suffix to get result
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    for (int x : result) {
        cout << x << " ";
    }
}

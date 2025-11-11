#include<bits/stdc++.h>
using namespace std;

// max product 

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        // If prefix becomes 0, reset it to 1 before multiplying
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        ans = max({ans, prefix, suffix});
    }

    return ans;
}

int main(){
    vector<int>nums = {2,3,-2,4,-1};
    int ans=  maxProduct(nums);
    cout<<ans<<endl;
}
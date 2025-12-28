// weekly contest 482

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
3788. Maximum Score of a Split
Solved
Medium
premium lock icon
Companies
Hint
You are given an integer array nums of length n.

Choose an index i such that 0 <= i < n - 1.

For a chosen split index i:

Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i].
Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].
The score of a split at index i is defined as:

score(i) = prefixSum(i) - suffixMin(i)

Return an integer denoting the maximum score over all valid split indices.
*/


    long long maximumScore(vector<int>& nums) {
        
    int n = nums.size();

    vector<int> suffixMin(n);
    suffixMin[n-1] = nums[n-1];

    for(int i = n-2; i >= 0; i--){
        suffixMin[i] = min(suffixMin[i+1], nums[i]);
    }

   ll prefixSum = 0;
    ll ans = INT_MIN;

    for(ll i = 0; i < n-1; i++){
        prefixSum += nums[i];
        ans = max(ans, prefixSum - suffixMin[i+1]);
    }

    return ans;
    }



/*

Code
Testcase
Testcase
Test Result
3789. Minimum Cost to Acquire Required Items


You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.


Example 1:

Input: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2

Output: 3

Explanation:

After buying three type 3 items, which cost 3 * 1 = 3, the total contribution to type 1 is 3 (>= need1 = 3) and to type 2 is 3 (>= need2 = 2).
Any other valid combination would cost more, so the minimum total cost is 3.
*/


// ???
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
             long long ans = LLONG_MAX;

       
        for (int x = max(need1, need2); x <= need1 + need2; x++) {
            long long cost = 1LL * x * costBoth;

            int rem1 = max(0, need1 - x);
            int rem2 = max(0, need2 - x);

            cost += 1LL * rem1 * cost1;
            cost += 1LL * rem2 * cost2;

            ans = min(ans, cost);
        }

        return ans;

    }


 





/*
🟢 LeetCode 1929 — Concatenation of Array
📘 Problem Statement

You are given an integer array nums of length n.

You want to create an array ans of length 2n where:

ans[i] = nums[i] for 0 ≤ i < n

ans[i + n] = nums[i] for 0 ≤ i < n

In other words, ans is formed by concatenating nums with itself.


Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]


*/

#include<bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

      int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans(2 * n);

    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;

}


// 🟡 Problem 2 — Two Sum
// 📘 Problem Statement

// You are given an array of integers nums and an integer target.

// Your task is to return the indices of the two numbers such that they add up to target.

// You may assume that each input has exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Input:
// nums = [2,7,11,15]
// target = 9

// Output:
// [0,1]

// concept : hashing


vector<int>sums(vector<int> &nums,int target){

    int n = nums.size();
    unordered_map<int,int> mp;
    //vector<int>ans;

   // for(int i : nums) mp[i]++;

    for(int i=0;i<n;i++){
        int diff = target - nums[i];
           if(mp.find(diff) != mp.end()){
               return{i,mp[diff]};
           }

           mp[nums[i]] = i;
    }

    return {-1,-1};
}


// 🟡 Problem 3 — Subarray Sum Equals K
// 📘 Problem Statement

// Given an integer array nums and an integer k,
// return the total number of continuous subarrays whose sum equals to k

// Input: nums = [1,1,1], k = 2
// Output: 2
// Explanation: The subarrays are [1,1] at positions [0,1] and [1,2].


/*
Idea:

Maintain running sum prefix_sum

Keep map sum_freq → number of times this sum has occurred

For each element:

count += sum_freq[prefix_sum - k]

sum_freq[prefix_sum]++
*/


/*

 int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_map<int, int> sum_freq;
    sum_freq[0] = 1; // important: empty prefix sum
    int prefix_sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];

        if (sum_freq.find(prefix_sum - k) != sum_freq.end()) {
            count += sum_freq[prefix_sum - k];
        }

        sum_freq[prefix_sum]++;
    }

    cout << count << "\n";

   */
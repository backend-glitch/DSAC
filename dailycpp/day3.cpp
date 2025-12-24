// 📌 Problem Statement

// Given an array of integers nums and an integer k,
// find the maximum sum of any contiguous subarray of size k.

// Input:
// nums = [2, 1, 5, 1, 3, 2]
// k = 3

// Output:
// 9


#include<bits/stdc++.h>
using namespace std;

int subsum(vector<int>& nums,int k){

    int n = nums.size();

    int curr_sum = 0;


    for(int i=0;i<n;i++) curr_sum += nums[i];

    int max_sum = curr_sum;

    for(int i=k;i<n;i++){
        curr_sum += nums[i];
        curr_sum -= nums[i-k];

        max_sum = max(max_sum ,curr_sum);
    }

    return max_sum;
    
}

// LeetCode 53 – Maximum Subarray
// 📌 Problem Statement

// Given an integer array nums,
// find the subarray with the largest sum, and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation:
// [4, -1, 2, 1] → sum = 6


int subssum(vector<int>& nums){
    int n = nums.size();

    int cur_sum = 0;
    int max_sum = INT_MIN;

    for(int i : nums){
      
        cur_sum += i;
        max_sum = max(max_sum, cur_sum);
      
        if(cur_sum < 0) cur_sum = 0;
    }

    return max_sum;
}

/*

🟡 Problem: LeetCode 121 – Best Time to Buy and Sell Stock
📌 Problem Statement

You are given an array prices where prices[i] is the price of a given stock on the i-th day.

You want to maximize your profit by choosing one day to buy and a different day to sell in the future.

Return the maximum profit you can achieve.
If you cannot achieve any profit, return 0.


Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:
Buy on day 2 (price = 1)
Sell on day 5 (price = 6)
Profit = 6 − 1 = 5

*/

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for(int price : prices){
        min_price = min(min_price, price);          // best buy so far
        max_profit = max(max_profit, price - min_price); // best sell
    }
    return max_profit;
}

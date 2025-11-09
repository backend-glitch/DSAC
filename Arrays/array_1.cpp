/*
// maximum subarray problem
 🔗 Problem: https://leetcode.com/problems/maximum-subarray
 🧠 Approach: kadane algo , vectors arrays
 ⏱️ Time: O(n)
 📦 Space: O(n
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        
  // take cuurentsum and maxsum
        int curr_sum = 0;
        int max_sum = INT_MIN;

        //find the sum
      for(int i = 0;i < nums.size();i++){
        curr_sum += nums[i];

        //compare with maxsum
       max_sum = max(max_sum,curr_sum);
       
       //if currsum goes less than 0 ,then remove all values.
        if(curr_sum < 0){
             curr_sum = 0;
        }

      
    }
    //return ans
    return  max_sum; 
    }
    
    int main(){

    vector<int> nums = {2, -1, 2, 3, -9, 5, 1};
    int ans = maxSubArray(nums);
    cout<<ans<<endl;
    }

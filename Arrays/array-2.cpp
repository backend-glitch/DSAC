#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    if (n < k) {
        cout << "Window size larger than array size!" << endl;
        return -1;
    }

    int windowSum = 0;
    // Calculate the sum of the first window
    for (int i = 0; i < k; i++){
        windowSum += nums[i];
    }
    int maxSum = windowSum;

    // Slide the window across the array
    for (int i = k; i < n; i++) {
        windowSum -= nums[i-k]; // remove the leftmost element of the sliding window
        windowSum += nums[i]; // add the new element to the rightmost side of sliding window

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}


// maximum subarray with sliding window value given
int main(){

  vector<int> nums2 = {4, -1, 2, 10, -2, 3, -1, 5, -3};
    int k = 4;

    cout << "Maximum sum of subarray of size " << k << " = "
         << maxSubarraySum(nums2, k) << endl;
}
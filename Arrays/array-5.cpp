# include <iostream>
# include <vector>
# include <climits>
#include<unordered_map>
using namespace std;

// pair sum

// 1. two pointers
vector<int> m1(vector<int>nums,int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int pair_sum = 0;

    while(left < right){
   pair_sum = nums[left] + nums[right];

   if (pair_sum  < target){
    left++;

   }else if (pair_sum > target){
    right--;
   
}else{
    return{left,right};
}

    }

}

//aproach 2 => hash maps
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement exists in the map
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        // Store current number with its index
        mp[nums[i]] = i; // key = number , value = index
    }

    return {}; // No solution
}

int main(){

    vector <int> nums = {2,7,11,15};
    int target = 26;

    vector<int> ans_1= m1(nums,target);
    cout<<nums[ans_1[0]]<<" "<<nums[ans_1[1]]<<endl;
    cout<<ans_1[0]<<" "<<ans_1[1]<<endl;
}


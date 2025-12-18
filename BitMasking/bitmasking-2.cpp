#include<bits/stdc++.h>
#include <vector>

using namespace std;


//approach 1
int optimised(vector<int> &nums){

    int ans = 0;
    for(int i : nums) ans ^= i;
    return ans;

}

 //approach 2
int singleNumber(vector<int> &nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i : nums) mp[i]++;

        for(int j = 0;j <= n;j++){

            if(mp[nums[j]] == 1) return nums[j];

        }
  return -1;
    }
   
    int main(){
  vector<int> nums = {2,1,2,2};
  int ans = singleNumber(nums);
  std::cout<<ans<<endl;
    }

 #include <bits/stdc++.h>
 using namespace std;
 
 //approach => Boyer–Moore Voting Algorithm
  int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }


    // approach => hashing map
     int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        // count frequency of each element
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2)
                return num; // found majority early
        }

        // theoretically, should never reach here if majority exists
        return -1;
    }


    int main(){

        vector<int> nums = {1,2,2,1,1,1,2};
      int ans = majorityElement(nums);
       cout<<ans<<endl;
    }
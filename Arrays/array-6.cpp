# include <iostream>
# include <vector>
# include <climits>
#include <unordered_map>
using namespace std;

// buy and sell stock
// two pointers

int mp(vector<int>&nums){
int max_profit = 0;
int best_buy = nums[0];
int n = nums.size();

for (int i = 1;i<n;i++){
 if (nums[i] > best_buy){
    max_profit = max(max_profit,nums[i]-best_buy);
 }

 best_buy = min(best_buy,nums[i]);
}
return {max_profit};
}

// container with maximum water.
// two pointers

int max_ans(vector<int>&heights){
    int n = heights.size();
    int left = 0;
    int right = n-1;
    int width = 0;
    int height = 0;
    int current_area =0;
    int max_area = 0;

    while(left<right){
        width = abs(right-left);
        height= min(heights[left],heights[right]);
        current_area  = width * height;
      
        max_area = max(max_area,current_area);

        if(heights[left] < heights[right]){
          left++;
        }else{
            right--;
        }
    }
    return{max_area};
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};
   int ans = mp(prices);
   cout<<"max_profit:"<<ans<<endl;

   cout<<endl;

   vector<int> height = {1,8,6,2,5,4,8,3,7};
   int ans_1 = max_ans(height);
   cout<<"max_area: "<<ans_1;
}
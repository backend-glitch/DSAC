# include <iostream>
# include <vector>
# include <climits>
#include <unordered_map>
using namespace std;

// search in rotated sorted  array.
int rsa(vector<int>&nums,int target){

    int n = nums.size();

    int left = 0;
    int right = n-1;

    while(left <= right){

        int mid = left +(right - left)/2;

        if(nums[mid] == target){
            return mid;
        }
        if (nums[left] < nums[mid]){// left sorted.
       
          if(nums[left] <= target && target <= nums[mid]){ 
            right = mid -1;
          }else{
            left = mid+1;
          }
        }else{// right sorted.
            if(nums[mid] <= target && target <= nums[right]){ 
                left = mid+1;
            }else{
            right = mid-1;
            }
            
          }
        }
    }

// peak element
int peak(vector<int> &nums){
    
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is less than right neighbor,
        // then a peak lies on the right side
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } 
        // Otherwise, the peak lies on the left side (including mid)
        else  if (nums[mid] > nums[mid+1]){
            right = mid;
        }else{
            return left;
        }
    
    }
  
}


int main(){

    vector<int> nums ={3,4,5,6,7,0,1,2};
    int target = 4;
    
    int ans = rsa(nums,target);
    cout<<ans;

    cout<<endl;

       int ans_1 = peak(nums);
       cout<<ans_1;

}
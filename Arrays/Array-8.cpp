# include <iostream>
# include <vector>
# include <climits>
#include <unordered_map>
using namespace std;

// binary search
int binary_1(vector<int>&nums,int target){
   int n = nums.size();
    int left =0;
    int right = n-1;

    while(left <= right){
        int mid = left + (right-left)/2;
    
        if(nums[mid] > target){
            right = mid-1;
        }else if(nums[mid]<target){
            left = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

//binary using recursion.
int binary_2(vector<int> &nums,int target,int left,int right){

   int n = nums.size();

   if(left<=right){
    int mid = left+(right-left)/2;

    if(nums[mid] > target){
        return binary_2(nums,target,left,mid-1);
    }else if(nums[mid]<target){
      return binary_2(nums,target,mid+1,right);  
    }else{
        return mid;
    }
   }
}



int main(){

     vector<int> nums = {-1,0,3,4,5,12};
     int target = 5;

     int ans_1 = binary_1(nums,target);
     cout<<"ans_1: "<<ans_1;

     cout<<endl;

     int n = nums.size();
     int ans_2 = binary_2(nums,target,0,n-1);
     cout<<"ans_2: "<<ans_2;
}
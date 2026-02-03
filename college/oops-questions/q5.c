/*
input : 
5
{1 2 3 4 5}

ouput:
{4}
{1,1,2}
{3,1}
{1,1,1,1}
*/


#include<stdio.h>

void subsum(int nums[], int n, int target, int level, int currnum[], int size){

    if(target == 0){

        for(int i = 0;i<size;i++) printf("%d",currnum[i]);
        
        printf(" ");
       

        return;
    }

    for(int i=level;i<n;i++){

        if(nums[i] <= target){
            currnum[size] = nums[i];

            subsum(nums,n,target-nums[i],i,currnum,size+1);
        }
    }



}

int main(){

    // int n;
    // scanf("%d",&n);

    // int arr[n];
    // for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    // int target;
    // scanf("%d",&target);

    int n =5;
    int arr[] = {1,2,3,4,5};

    int target = 4;

    int currnum[5];

    subsum(arr,n,target,0,currnum,0);
}
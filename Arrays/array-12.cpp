// maximum equal  choco to K children

#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int>& candies, long long k,int mid){
  
    long long childrencount = 0;
    
 for(int c :candies){
    childrencount += c/mid;
 }
 return childrencount >= k;
}

    int maximumCandies(vector<int>& candies, long long k) {

        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

  while(left<=right){
    long long mid = left + (right - left) / 2;
          if (isPossible(candies,k,mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
  }
            return result;
    }

int main(){

    vector<int> candies = {5,8,6};
    int children = 3;

    int answer = maximumCandies(candies,children);
    cout<<answer<<endl;
}
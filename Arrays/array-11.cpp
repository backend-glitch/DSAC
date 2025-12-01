#include<bits/stdc++.h>
using namespace std;

bool istimepossible(vector<int>& piles,int givenpilestime,int totalhours){//if given mid vlaue is satisying total hours or not.

  int actualpilestime = 0;
  for(int &p : piles){
   actualpilestime += p/givenpilestime;


    if( p % givenpilestime != 0){//if it will come decimal like 0.7 ,so we can consider to be 1;
        actualpilestime++;
    }
  }
  return actualpilestime <= totalhours;
  }

      int minEatingSpeed(vector<int>& piles, int h) {
        
        int n  = piles.size();
        int left = 1;
        int right = *max_element(begin(piles),end(piles));

        while(left < right){
            int mid = left+(right-left)/2;

            if(istimepossible(piles,mid,h)){
               
                right = mid;
                }else{

                    left = mid + 1;
                
            }
        }
            return left;
        
    }

    int main(){
      vector<int> piles = {3,6,7,11};
      int hours  = 8;

      int ans = minEatingSpeed(piles,hours);
      cout<<ans<<endl;

    }
#include<bits/stdc++.h>
using namespace std;

// weekly contest 481

/*

3783. Mirror Distance of an Integer

You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.


Input: n = 25

Output: 27
*/


  int mirrorDistance(int n) {
        
    //    string num = "";
    //    int ans;
     //   num = reverse(n.begin(),n.end())
  
  int ans;
  int n2 = n;
  int rev = 0;

     while(n2 > 0){
     
      rev = rev*10 + n2%10;
      n2 /= 10;
    

     }
     ans = abs(n - rev);

        return ans;
    }



/*
3784. Minimum Deletion Cost to Make All Characters Equal

You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.
*/

#define ll long long

 long long minCost(string s, vector<int>& cost) {
        

   vector<ll> keep(26, 0);
  ll total = 0;

    for(int i = 0; i < s.size(); i++){
        total += cost[i];
        keep[s[i] - 'a'] += cost[i];
    }

    ll max_keep = 0;
    for(ll c : keep){
        max_keep = max(max_keep, c);
    }

    return total - max_keep;

    }


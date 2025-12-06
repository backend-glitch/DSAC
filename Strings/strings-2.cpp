/*
longest substring without duplicates

input : "pwwkew"
output : 3 -> (kew)
*/

#include <bits/stdc++.h>
using namespace std;


int Maximumsub(string word){
//sliding window

int left = 0;
int max_len = 0;

vector<int> mp(256,-1);

for (int r = 0;r < word.size();r++){

    if (mp[word[r]] >= left){
        left = mp[word[r]] + 1;

    }

    mp[word[r]] = r; //tracking index to move left pointer afterwards.

    max_len = max(max_len,r-left+1);// (max_length, current_window_size).
    
   }
return max_len;

}

int main(){
    
    string word = "pwwkew";

   int ans =  Maximumsub(word);
   cout<<ans<<endl;

}
/*
input : "the sky blue"
output : "blue sky the"
*/

#include <bits/stdc++.h>
using namespace std;

      string reverseWords(string s) {
         int n = s.length();
         string ans = "";

  reverse (s.begin(),s.end());
  
  for(int i=0;i<n;i++){
    string word = "";// here we use " "
    while(i<n && s[i] != ' '){// here we use ' '
      word += s[i];// for every word.
      i++;
    }

    reverse( word.begin(),word.end());//if senternce contain more than 1 spaces
      if(word.length() > 0){
        ans += " " + word;
      
    }
  }
  return ans.substr(1); // .substr(starting_index, length) // length unprovided => considers remaining length by default !
  
    }

 int main(){

    string word = "the sky blue";

    string ans = reverseWords(word);
    cout<<"The reverse sentence : "<<ans;


 }

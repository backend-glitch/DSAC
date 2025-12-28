#include<bits/stdc++.h>
using namespace std;

    int firstUniqChar(string s) {
        
        int n = s.length();
        unordered_map<char,int> mp;
        
        for(char c : s) mp[c]++;

        for(int c = 0;c < n;c++){
            if(mp[s[c]] == 1) return c;
        }
           
        return -1;
    }

    int main(){

        string word = "lleetcode";
        int index = firstUniqChar(word);
        cout<<index<<endl;
        
    }
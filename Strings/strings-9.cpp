/*
451. Sort Characters By Frequency

Input: s = "tree"
Output: "eert"

*/

#include<bits/stdc++.h>
using namespace std;

  string frequencySort(string s) {
            
        // Frequency vector for all characters
        vector<int> freq(256, 0);
        for(char c : s) freq[c]++;

        // Create a vector of characters that appear in s
        vector<char> chars;
        for(int i = 0; i < 256; i++){
            if(freq[i] > 0) chars.push_back(i);
        }

        // Sort characters by frequency descending [&](
        sort(chars.begin(), chars.end(),[&](char a, char b){
            return freq[a] > freq[b];
        });

        // Build the answer string
        string ans = "";
        for(char c : chars){
            ans += string(freq[c], c); // repeat char by its frequency
        }

        return ans;
    }


#include<bits/stdc++.h>
using namespace std;

/*
✅ Today’s Tasks (Reminder)

LC 217 — Contains Duplicate (Easy)

LC 242 — Valid Anagram (Medium)

LC 49 — Group Anagrams (Medium, optional stretch)
*/


// LC 217
// 📘 Statement

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Input: nums = [1,2,3,1]
// Output: true

// concept : hashmap

bool isdup(vector<int> nums){

    int n = nums.size();
    unordered_map<int,int> mp;

    for(int i : nums) mp[i]++;

    for(int i : nums){
        if(mp[i] > 1) return true;
    }
 return false;
}



// 🧩 Problem 2 — Valid Anagram (Medium) LC 242
// 📘 Statement

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An anagram means both strings contain the same characters with the same frequencies, just possibly in a different order.

// Input: s = "anagram", t = "nagaram"
// Output: true

// concept : hashmap

bool isdup2(string word1 , string word2){

    int n1 = word1.length();
    int n2 = word2.length();

    if(n1 != n2) return;

    unordered_map<char,int> mp1;
     unordered_map<char,int> mp2;

    for(char i : word1) mp1[i]++;
     for(char i : word2) mp2[i]++;

     for(char j : word1){
        if(mp1[j] != mp2[j]) return false;
     }

    return true;
}




// 🧩 Problem 3 — Group Anagrams (Medium, Optional)
// 📘 Statement

// Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output:
// [
//   ["eat","tea","ate"],
//   ["tan","nat"],
//   ["bat"]
// ]

// ans = ""
vector<vector<string>> groupAnagrams(vector<string>& words) {

    unordered_map<string, vector<string>> mp;

    for (string word : words) {
        string key = word;
        sort(key.begin(), key.end());   // key generation
        mp[key].push_back(word);        // grouping
    }

    vector<vector<string>> ans;
    for (auto &p : mp) {
        ans.push_back(p.second);
    }

    return ans;
}



int main(){

}
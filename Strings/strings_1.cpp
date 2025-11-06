/*
// Valid palindrome
 🔗 Problem: https://leetcode.com/problems/valid-palindrome
 🧠 Approach: strings + two pointers 
 ⏱️ Time: O(n)
 📦 Space: O(n
*/

#include<bits/stdc++.h>
using namespace std;

 bool isPalindrome(string s) {
        
            int left = 0, right = s.size() - 1;

            // start the pointers .
    while (left < right) {
        // ignore non-alphanumeric characters eg. @,!,#.
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        // compare characters (case insensitive)
        if (tolower(s[left]) != tolower(s[right]))
            return false;

            //move the pointers
        left++;
        right--;
    }

    return true;
    }
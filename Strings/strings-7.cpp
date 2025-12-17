#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    unordered_map<char, int> need, window;

    // Frequency of characters in t
    for (char c : t)
        need[c]++;

    int required = need.size(); // unique characters needed
    int formed = 0;

    int l = 0, r = 0;
    int minLen = INT_MAX, start = 0;

    while (r < s.size()) {
        char c = s[r];
        window[c]++;

        if (need.count(c) && window[c] == need[c])
            formed++;

        // Try to shrink the window
        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s[l];
            window[leftChar]--;

            if (need.count(leftChar) && window[leftChar] < need[leftChar])
                formed--;

            l++;
        }

        r++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;   // no spaces (like LeetCode)

    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);

    if (result == "")
        cout << "No valid window found" << endl;
    else
        cout << "Minimum window substring: " << result << endl;

    return 0;
}

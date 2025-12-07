 #include <bits/stdc++.h>
 using namespace std;
 
 
 bool checkInclusion(string s1, string s2) {
        
            if (s1.size() > s2.size()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);
    int k = s1.size();

    // count frequency of first string
    for (char c : s1)
        freq1[c - 'a']++;

    // initial window in s2
    for (int i = 0; i < k; i++)
        freq2[s2[i] - 'a']++;

    if (freq1 == freq2) return true;

    // slide the window
    for (int i = k; i < s2.size(); i++) {
        freq2[s2[i] - 'a']++;          // include new char
        freq2[s2[i - k] - 'a']--;      // remove old char

        if (freq1 == freq2)
            return true;
    }

    return false;
    }

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout<<checkInclusion(s1,s2); // 1 => True
}
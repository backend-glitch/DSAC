# include <iostream>
# include <vector>
# include <climits>
#include <unordered_map>

using namespace std;


//remove occurences

string removeOccurrences(string s, string part) {
    while (s.find(part) != string::npos) {   // == npos :means string not found.  // keep checking if part exists
        int pos = s.find(part);              // position where part is found
        s.erase(pos, part.size());           // remove that part
    }
    return s;
}

//strings permutations


int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(s, part);   // Output: dab
    return 0;
}



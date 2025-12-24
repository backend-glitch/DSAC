// 🧩 Problem (Example)

// Given an array of integers, find the number of pairs (i, j) such that i < j and a[i] + a[j] = k.

#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;
    long long countPairs = 0;

    for (int i = 0; i < n; i++) {
        int need = k - a[i];

        if (freq.find(need) != freq.end()) {
            countPairs += freq[need];
        }

        freq[a[i]]++;
    }

    cout << countPairs << "\n";

    return 0;
}

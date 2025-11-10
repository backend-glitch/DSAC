#include<bits/stdc++.h>
using namespace std;

vector<int> find_sublist_sum(vector<int> nums, int target) {
    int n = nums.size();

    // Try all combinations using bitmasking
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> subset;
        int total = 0;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {  // if bit j is set, include nums[j]
                subset.push_back(nums[j]);
                total += nums[j];
            }
        }

        if (total == target)
            return subset; // Found one valid subset
    }

    return {}; // Return empty vector if not found
}

int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = find_sublist_sum(nums, target);

    if (!result.empty()) {
        cout << "Sublist with target sum: ";
        for (int x : result)
            cout << x << " ";
        cout << endl;
    } else {
        cout << "No sublist found." << endl;
        cout << "Reversed sorted list: ";
        sort(nums.begin(), nums.end(), greater<int>());
        for (int x : nums)
            cout << x << " ";
        cout << endl;
        cout << "False" << endl;
    }

    return 0;
}


/*
| mask (dec) | mask (bin) | bits checked (j=0..3)           | Subset formed | Sum    | Matches target? |
| ---------- | ---------- | ------------------------------- | ------------- | ------ | --------------- |
| 1          | 0001       | j=0 ✅ include 2                 | [2]           | 2      | ❌               |
| 2          | 0010       | j=1 ✅ include 1                 | [1]           | 1      | ❌               |
| 3          | 0011       | j=0 ✅ (2), j=1 ✅ (1)            | [2, 1]        | 3      | ❌               |
| 4          | 0100       | j=2 ✅ (5)                       | [5]           | 5      | ❌               |
| 5          | 0101       | j=0 ✅ (2), j=2 ✅ (5)            | [2, 5]        | 7      | ❌               |
| 6          | 0110       | j=1 ✅ (1), j=2 ✅ (5)            | [1, 5]        | 6      | ❌               |
| 7          | 0111       | j=0 ✅ (2), j=1 ✅ (1), j=2 ✅ (5) | [2, 1, 5]     | 8      | ❌               |
| 8          | 1000       | j=3 ✅ (6)                       | [6]           | 6      | ❌               |
| 9          | 1001       | j=0 ✅ (2), j=3 ✅ (6)            | [2, 6]        | 8      | ❌               |
| 10         | 1010       | j=1 ✅ (1), j=3 ✅ (6)            | [1, 6]        | 7      | ❌               |
| 11         | 1011       | j=0 ✅ (2), j=1 ✅ (1), j=3 ✅ (6) | [2, 1, 6]     | **9**  | ✅               |
| 12         | 1100       | j=2 ✅ (5), j=3 ✅ (6)            | [5, 6]        | **11** | —               |
| 13         | 1101       | j=0 ✅ (2), j=2 ✅ (5), j=3 ✅ (6) | [2, 5, 6]     | 13     | —               |
| 14         | 1110       | j=1 ✅ (1), j=2 ✅ (5), j=3 ✅ (6) | [1, 5, 6]     | 12     | —               |
| 15         | 1111       | all bits ✅                      | [2, 1, 5, 6]  | 14     | —               |




mask = 11  → binary = 1011

Inner loop:
j = 0 → (mask & (1<<0)) = 1 → include nums[0]=2
subset = [2], total = 2

j = 1 → (mask & (1<<1)) = 2 → include nums[1]=1
subset = [2, 1], total = 3

j = 2 → (mask & (1<<2)) = 0 → skip
subset = [2, 1], total = 3

j = 3 → (mask & (1<<3)) = 8 → include nums[3]=6
subset = [2, 1, 6], total = 9

Now total == target → return [2, 1, 6]


*/
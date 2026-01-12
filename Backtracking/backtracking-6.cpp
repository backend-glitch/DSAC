/*
input : 
5
{1 2 3 4 5}

ouput:
{4}
{1,1,2}
{3,1}
{1,1,1,1}
*/


#include <bits/stdc++.h>
using namespace std;

void subsum(vector<int>& coins, int target, int index, vector<int>& curr) {

    // base case

    if (target == 0) {
        cout << "{ ";
        for (int x : curr) cout << x << " ";
        cout << "}\n";
        return;
    }

    for (int i = index; i < coins.size(); i++) {
        
        if (coins[i] <= target) {

            curr.push_back(coins[i]);
            subsum(coins, target - coins[i], i, curr); 

            curr.pop_back();

        }
    }
}

int main() {
    vector<int> coins = {1, 2, 3, 4, 5};
    int target = 4;

    vector<int> curr;
    subsum(coins, target, 0, curr);

    return 0;
}

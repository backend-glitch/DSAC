#include <stdio.h>

// Recursive function to generate all combinations
void solve(int target, int coins[], int index, int current[], int len, int *first) {
    // Base Case: If we reach the target sum exactly
    if (target == 0) {
        if (!(*first)) printf(", "); // Comma between sets
        printf("{");
        for (int i = 0; i < len; i++) {
            printf("%d", current[i]);
            if (i < len - 1) printf(", ");
        }
        printf("}");
        *first = 0; // Update flag
        return;
    }

    // Iterate through coins starting from 'index' to avoid duplicates
    for (int i = index; i < 5; i++) {
        // Safety check: Prevent infinite loop if input has 0
        if (coins[i] <= 0) continue; 

        if (target - coins[i] >= 0) {
            current[len] = coins[i];
            // Recursion: Pass 'i' again to allow using the same coin multiple times
            solve(target - coins[i], coins, i, current, len + 1, first);
        }
    }
}

// Function required by the problem
void coins(int n, int arr[]) {
    printf("%d\n", n); // Print the target number first
    
    int buffer[100];   // Temp array to store combinations
    int first = 1;     // Flag to handle commas
    
    solve(n, arr, 0, buffer, 0, &first);
}

// Main function to read inputs and start the program
int main() {
    int n;
    int arr[5];

    // Read the target cost
    if (scanf("%d", &n) != 1) return 0;

    // Read the 5 coin denominations
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the solver
    coins(n, arr);

    return 0;
}
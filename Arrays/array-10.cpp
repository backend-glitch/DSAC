# include <iostream>
# include <vector>
# include <climits>
#include <unordered_map>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Ensure mid is even (so mid^1 gives its pair index)
        if (mid % 2 == 1) {
            mid--; 
        }

        // If pair is valid, move to right half
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } 
        // Otherwise, the single element is in left half (including mid)
        else {
            right = mid;
        }
    }
    return nums[left];  // left == right -> single element
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << "Single element: " << singleNonDuplicate(nums) << endl;
    return 0;
}



'''

Question:

Input: [2, 1, 5, 6]
Target sum: 9
Output: [2, 1, 6]
The sublist is one subset of the input whose elements add up to the target sum of 9.


'''
#Approach 1  => Two pointers
# continuos subarray

# --- Header (Input Section) ---
nums = list(map(int, input("Enter list elements: ").split()))
target = int(input("Enter target sum: "))

# --- Body (Main Logic) ---
def find_sublist_sum(nums, target):
    n = len(nums)
    
    # Try all possible starting points
    for i in range(n):
        current_sum = 0
        temp = []
        
        # Try all sublists starting from i
        for j in range(i, n):
            current_sum += nums[j]
            temp.append(nums[j])
            
            # Check if sum equals target
            if current_sum == target:
                return temp
    
    # If not found
    return []

# --- Footer (Output Section) ---
result = find_sublist_sum(nums, target)
result1 = find_sublist_sum(nums, target)


if result:
    print("Sublist with target sum:", result)
else:
    print("No sublist found.")
    print("Reversed sorted list:", list(reversed(sorted(nums))))
    print(False)



#Approach 2  => Backtracking

def find_sublist_sum(nums, target):
    result = []

    def backtrack(index, current, total):
        # Base case: found the target sum
        if total == target:
            result.extend(current)
            return True
        # Base case: end of list
        if index >= len(nums):
            return False

        # Include current number
        if backtrack(index + 1, current + [nums[index]], total + nums[index]):
            return True
        # Exclude current number
        if backtrack(index + 1, current, total):
            return True

        return False

    # Return result if found, else empty list
    if backtrack(0, [], 0):
        return result
    else:
        return []



#Approach 3  => Bitmasking (Subset Enumeration using Bit Manipulation)

def find_sublist_sum(nums, target):
    n = len(nums)
    
    # Check every possible combination using bits
    for mask in range(1, 1 << n):  # 1 to 2^n - 1
        subset = []
        total = 0
        for j in range(n):
            if mask & (1 << j):  # if bit j is set, include nums[j]
                subset.append(nums[j])
                total += nums[j]
        if total == target:
            return subset
    return []


'''

| mask (dec) | mask (bin) | bits checked (j=0..3)           | Subset formed | Sum    | Matches target? |
| ---------- | ---------- | ------------------------------- | ------------- | ------ | --------------- |
| 1          | 0001       | j=0 ✅ include 2                 | [2]           | 2      | ❌               |
| 2          | 0010       | j=1 ✅ include 1                 | [1]           | 1      | ❌               |
| 3          | 0011       | j=0 ✅ (2), j=1 ✅ (1)            | [2, 1]        | 3     | ❌               |
| 4          | 0100       | j=2 ✅ (5)                       | [5]           | 5      | ❌               |
| 5          | 0101       | j=0 ✅ (2), j=2 ✅ (5)            | [2, 5]        | 7     | ❌               |
| 6          | 0110       | j=1 ✅ (1), j=2 ✅ (5)            | [1, 5]        | 6     | ❌               |
| 7          | 0111       | j=0 ✅ (2), j=1 ✅ (1), j=2 ✅ (5) | [2, 1, 5]     | 8    | ❌               |
| 8          | 1000       | j=3 ✅ (6)                       | [6]           | 6        |❌               |
| 9          | 1001       | j=0 ✅ (2), j=3 ✅ (6)            | [2, 6]        | 8      | ❌               |
| 10         | 1010       | j=1 ✅ (1), j=3 ✅ (6)            | [1, 6]        | 7      | ❌               |
| 11         | 1011       | j=0 ✅ (2), j=1 ✅ (1), j=3 ✅ (6) | [2, 1, 6]     | **9** | ✅               |
| 12         | 1100       | j=2 ✅ (5), j=3 ✅ (6)            | [5, 6]        | **11**  | —               |
| 13         | 1101       | j=0 ✅ (2), j=2 ✅ (5), j=3 ✅ (6) | [2, 5, 6]     | 13    | —               |
| 14         | 1110       | j=1 ✅ (1), j=2 ✅ (5), j=3 ✅ (6) | [1, 5, 6]     | 12    | —               |
| 15         | 1111       | all bits ✅                      | [2, 1, 5, 6]  | 14     | —               |


'''


'''

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


'''
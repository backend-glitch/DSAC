# find the first and last occurence of a number using recursive binary search
def first_occurrence(nums, target, left, right):
    if left > right:
        return -1

    mid = (left + right) // 2

    if nums[mid] == target:
        # keep searching left for first occurrence
        left_index = first_occurrence(nums, target, left, mid - 1)
        
        if left_index == -1:
            return mid
        else:
            return left_index

    elif nums[mid] < target:
        return first_occurrence(nums, target, mid + 1, right)
    else:
        return first_occurrence(nums, target, left, mid - 1)

def last_occurrence(nums, target, left, right):
    if left > right:
        return -1

    mid = (left + right) // 2
    
    if nums[mid] == target:
        # keep searching right for last occurrence
        right_index = last_occurrence(nums, target, mid + 1, right)
        
        if right_index == -1:
            return mid # we got the answer
        else:
            return right_index # go more towards right.
            
    elif nums[mid] < target:
        return last_occurrence(nums, target, mid + 1, right)
    else:
        return last_occurrence(nums, target, left, mid - 1)

# Main
n = int(input())
nums = list(map(int, input().split()))
target = int(input())

first = first_occurrence(nums, target, 0, n-1)
last = last_occurrence(nums, target, 0, n-1)

if first == -1 or last == -1:
    print("NO OCCURRENCES")
else:
    print(first, last)
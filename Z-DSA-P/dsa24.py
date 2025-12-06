nums = [5,2,8,3]
n = len(nums)

# bubble sort
for i in range(n):
    for j in range(0 , n-i-1):
        if nums[j] > nums[j+1]:
            nums[j], nums[j+1] = nums[j+1], nums[j]

print(nums)


# selection sort
nums1 = [64,25,12,22,11]
n1 = len(nums1)

for i in range(n1):
    min_idx = i
    for j in range(i+1,n1):
       if nums1[j] < nums1[min_idx]:
          min_idx = j
    
    nums1[i] , nums1[min_idx] = nums1[min_idx] , nums1[i]
print(nums1)
   
# insertion sort
nums2 = [12,11,13,5,6]
n2 = len(nums2)

for i in range(1,n2):
    key = nums2[i]
    j = i-1

    while j>=0 and key < nums2[j]:
        nums2[j+1] = nums2[j]
        j -= 1
    nums2[j+1] = key

print(nums2)

# merge sort

def merge_sort(arr):
    if len(arr) <= 1:
        return arr  # Base case: a single element is already sorted

    # Divide
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    # Merge
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    # Merge two sorted lists
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Add remaining elements
    result.extend(left[i:])
    result.extend(right[j:])
    return result

# Example
nums3 = [38, 27, 43, 3, 9, 82, 10]
sorted_nums = merge_sort(nums3)
print(sorted_nums)

# Merge Sort

def merge_sort(arr):
    # Base case: if array has 1 or 0 elements, it is already sorted
    if len(arr) <= 1:
        return arr

    # Step 1: Find the middle index
    mid = len(arr) // 2

    # Step 2: Recursively sort left half and right half
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])
    
 
    # Step 3: Merge the two sorted halves
    return merge(left_half, right_half)


def merge(left, right):
    sorted_list = []
    i = j = 0

    # Compare elements and add the smaller one
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    # Add remaining elements from left (if any)
    while i < len(left):
        sorted_list.append(left[i])
        i += 1

    # Add remaining elements from right (if any)
    while j < len(right):
        sorted_list.append(right[j])
        j += 1

    return sorted_list


# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original:", arr)
print("Sorted:", merge_sort(arr))


# to print array after each iteration .

def merge_sort(arr, l, r):
    if l < r:
        mid = (l + r) // 2

        # Sort first and second halves
        merge_sort(arr, l, mid)
        merge_sort(arr, mid + 1, r)

        merge(arr, l, mid, r)

        # 🔹 Print the whole array after each merge
        print(arr)


def merge(arr, l, mid, r):
    n1 = mid - l + 1
    n2 = r - mid

    # Create temp arrays
    L = arr[l:mid+1]
    R = arr[mid+1:r+1]

    i = j = 0
    k = l

    # Merge back into arr[l..r]
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Copy remaining elements
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original:", arr)
merge_sort(arr, 0, len(arr) - 1)
print("Final Sorted:", arr)
def merge_sort(arr, l, r):
    if l < r:
        mid = (l + r) // 2

        # Sort first and second halves
        merge_sort(arr, l, mid)
        merge_sort(arr, mid + 1, r)

        merge(arr, l, mid, r)

        # 🔹 Print the whole array after each merge
        print(arr)


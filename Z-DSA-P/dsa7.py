# binary search
nums = [-9,-7,0,1,2,4,6]
target = 0
left,right = 0,len(nums)-1

while left <= right:
    mid = left + (right - left)//2
    if nums[mid] == target:
        print(mid)
        break
    elif nums[mid]> target:
        right = mid - 1
    else :
        left = mid + 1
    
        
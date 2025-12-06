# remove duplicates
nums = [0,0,1,1,2,2,3,3,4]

n = len(nums)
left = 0

for right in range(1,n):
    if nums[right] != nums[right-1]:
        left += 1
        nums[left] = nums[right]

print("Original numbers: ",left)
print("new array:",nums[:left+1])
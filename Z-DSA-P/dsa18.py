# move zeroes to the end
nums = [1,3,0,4,0,2]

l = 0
for r in range(len(nums)):
    if nums[r]:
        nums[l],nums[r] = nums[r],nums[l]
        l += 1
print(nums)
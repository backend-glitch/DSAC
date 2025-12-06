# two sum 2
nums = [1,3,4,5,7,11]
target = 18

l,r = 0,len(nums)-1
    
while l < r:
    curr_sum = nums[l] + nums[r]
    if curr_sum > target :
        r -= 1
    elif curr_sum < target:
        l += 1
    else:
        print(l+1,r+1)
        break


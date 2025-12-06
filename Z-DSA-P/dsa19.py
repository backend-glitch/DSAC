# find disappeared numbers,
nums = [4,3,2,7,8,2,3,1]
n = len(nums)

for i in nums:
    index = abs(i)-1
    nums[index] = -abs(nums[index])

result = []
for  i,m  in enumerate(nums):
    if  m > 0:
        result.append(i+1)
print(*result)





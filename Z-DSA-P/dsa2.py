# maximum subarray
nums = [3,-4,5,4,-1,7,8]

max_sum = 0
curr_sum = 0

for i in nums :
    if curr_sum < 0:
        curr_sum = 0

    curr_sum += i
    max_sum = max(max_sum,curr_sum)

print(max_sum)

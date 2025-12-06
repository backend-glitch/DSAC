#PIVOT INDEX
nums = [1,7,3,6,5,6]

leftsum = 0
sum_1 = sum(nums)

for i,n in enumerate(nums):
    rightsum =  sum_1 - leftsum - n
    if rightsum == leftsum:
        print(i)
    leftsum += n



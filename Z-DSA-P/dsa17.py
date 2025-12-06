# majority element

nums = [1,2,1,1,2,2,2,2,1,1,1]

n = len(nums)
freq= {}

for i in nums:
    freq[i] = freq.get(i,0) + 1

for i in freq:
    if freq[i] >  n/2:
        print(i)

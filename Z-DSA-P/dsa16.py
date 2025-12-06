# to find the single element
nums = [1,1,2,4,2]

freq = {}

for i in nums:
    freq[i] = freq.get(i,0) + 1

for num in freq:
    if freq[num] == 1:
        print(num)

# two sum
#hash maps

nums = [2,10,-1,6,-5]
target = 5

mp = {}
for i,n in enumerate(nums):
    diff = target - n
    if diff in mp:
        print("Indices:")
        print(mp[diff],i)
    else:
        mp[n] = i

# duplicates
# hash maps

nums = [1,2,3,1]

hashset = set()

is_duplicate = True

for n in nums:
    if n in hashset:
        is_duplicate = True
        print(True)
    hashset.add(n)

is_duplicate = False
print(False)



# reverse string

s = ["h","e","l","o","o"]

l, r = 0, len(s) - 1

while l < r:
    s[l], s[r] = s[r], s[l]
    l, r = l+1 , r-1
print(s)
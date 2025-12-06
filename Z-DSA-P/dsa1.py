# comparing anagrams
# hash maps

s = "gram"
t = "marg"

count_s,count_t = {},{}

if len(s) != len(t):
    print("Not anagram")
else:
    for i in range(len(s)):
        count_s[s[i]] = 1 + count_s.get(s[i],0)
        count_t[t[i]] = 1 + count_t.get(t[i],0)

        is_anagram = True
        for c in count_s:
            if count_s[c] != count_t.get(c,0):
                is_anagram = False
                break
if is_anagram:
    print("yes anagram")
else:
    print("-1")
        


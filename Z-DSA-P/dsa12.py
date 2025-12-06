# isomorphic words
#hash maps

word1 = "add"
word2 = "egg"

w1,w2 = {},{}

for i in range(len(word1)):
    c1,c2 = word1[i],word2[i]

    if ((c1 in w1 and w1[c1] != c2) or (c2 in w2 and w2[c2] != c1)):
        print("false")
        break
    w1[c1] = c2
    w2[c2] = c1
print("true")

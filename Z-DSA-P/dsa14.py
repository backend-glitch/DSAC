# index of first occurence
#sliding window

haystack = "hello"
needle = "ll"

if needle == "":
    print(0)

for i in range(len(haystack) + 1 - len(needle)): #sliding window
    for j in range(len(needle)):
        if haystack[i+j] != needle[j]:
            break
        if j == len(needle)-1:
            print(i)

#length of the last word
word = "arjun and aman  "

i,length = len(word)-1,0

while word[i] == " ":
    i -= 1

while i >= 0 and word[i] != " ":
    length += 1
    i -= 1

print(length)
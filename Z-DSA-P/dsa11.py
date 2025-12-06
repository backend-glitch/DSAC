#valid palindrome
word = " annn aaa nnna "

left,right = 0,len(word)-1

while left < right:
    
    while left < right and not word[left].isalnum():
        left += 1
    while left < right and not word[right].isalnum():
        right -= 1

    if word[left].lower() != word[right].lower():
        print("lenght not equal")
        break

    left += 1
    right -= 1

print("yes")
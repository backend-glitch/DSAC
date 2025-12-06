def lengthOfLongestSubstring(s):
    n = len(s)
    max_len = 0

    for i in range(n):
        for j in range(i, n):

        
            substring = s[i:j+1]
            if len(substring) == len(set(substring)):  
                max_len = max(max_len, j - i + 1)

    return max_len


print(lengthOfLongestSubstring("pwwkew"))

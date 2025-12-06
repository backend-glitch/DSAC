'''
input : nums1 :  [4,1,2]
 nums2 : [1,3,4,2]
output : [-1,3,-1]
'''

'''
perfect square
'''

num = 14

left, right = 1, num

while left<= right:
    mid = (left + right)//2

    if mid*mid > num:
        right = mid - 1
    elif mid * mid <num:
        left = mid + 1
    else:
        print(True)
print(False)
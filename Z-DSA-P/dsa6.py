# merge sorted array

arr1 = [1,2,3,0,0,0]
arr2 = [2,5,6]

m = len(arr1)-1
n = len(arr2)-1
last = m + n - 1

while m>=0 and n>=0:
    if arr1[m] > arr2[n]:
        arr1[last]  = arr1[m]
        m -= 1
    else:
        arr1[last] = arr2[n]
        n -= 1
last -= 1

while n>=0:
    arr1[last] = arr2[n]
    n -= 1
    last -= 1
print(arr1)
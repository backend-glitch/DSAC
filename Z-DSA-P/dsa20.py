# recursive binary search

def r_binary(nums,target,st,end):
    
    n = len(nums)

    if(st <= end):
        mid = st + (end - st)//2

        if nums[mid] > target:
            return r_binary(nums,target,st,mid-1)
        elif nums[mid] < target:
            return r_binary(nums,target,mid+1,end)
        else:
            return(mid)

nums = [2,5,3,8,9,10,1]
target = 9

print(r_binary(nums,target,0,len(nums)-1))
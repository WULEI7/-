def BiSearch(num,x,n):
    left=0
    right=n-1
    while left<=right:
        for i in range(left,right+1):
            print(num[i],end=" ")
        print("")
        if x<num[left] or x>num[right]:
            return -1
        mid=(left+right)//2
        if(x==num[mid]):
            return mid
        if(x>num[mid]):
            left=mid+1
        if(x<num[mid]):
            right=mid-1
    return -1

num=[int(i) for i in input().split(" ")]
x=int(input())
n=len(num)
find=BiSearch(num,x,n)
print(find+1)
def Permutation(a,k,m):
    if k==m:
        for i in range(m+1):
            print(a[i],end=" ")
        print("")
    else:
        for i in range(k,m+1):
            t=a[i]
            a[i]=a[k]
            a[k]=t
            Permutation(a,k+1,m)
            t=a[i]
            a[i]=a[k]
            a[k]=t

a=[int(i) for i in input().split(" ")]
n=len(a)
a.sort()
Permutation(a,0,n-1)
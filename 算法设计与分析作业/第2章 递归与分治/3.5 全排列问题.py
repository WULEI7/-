def Permutation(a,k,m):
    if k==m:
        for i in range(m+1):
            print(a[i],end=" ")
        print("")
    else:
        for i in range(k,m+1):
            a[i],a[k]=a[k],a[i]
            Permutation(a,k+1,m)
            a[i],a[k]=a[k],a[i]

a=[int(i) for i in input().split(" ")]
n=len(a)
a.sort()
Permutation(a,0,n-1)
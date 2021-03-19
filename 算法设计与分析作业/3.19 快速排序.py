def partition(a,l,r):
    i=l-1
    for j in range(l,r):
        if a[j]<a[r]:
            i+=1
            a[i],a[j]=a[j],a[i]
    a[i+1],a[r]=a[r],a[i+1]
    return i+1

def quicksort(a,l,r):
    global time
    time+=1
    if l<r:
        m=partition(a,l,r)
        quicksort(a,l,m-1)
        quicksort(a,m+1,r)

a=[int(i) for i in input().split(" ")]
n=len(a)
time=0
quicksort(a,0,n-1)
print(time)
for i in range(n):
    print(a[i],end=" ")
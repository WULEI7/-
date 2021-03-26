def merge(a,b):
    c=[]
    i=j=0
    while i<len(a) and j<len(b):
        if a[i]<b[j]:
            c.append(a[i])
            i+=1
        else:
            c.append(b[j])
            j+=1
    while i<len(a):
        c.append(a[i])
        i+=1
    while j<len(b):
        c.append(b[j])
        j+=1
    return c

def merge_sort(list):
    global time #在函数中修改全局变量的值
    time+=1
    if len(list)<=1:
        return list
    middle=len(list)//2
    left=merge_sort(list[:middle])
    right=merge_sort(list[middle:])
    return merge(left,right)

list=[int(i) for i in input().split()]
time=0
list=merge_sort(list)
print(time)
len=len(list)
for i in range(len):
    print(list[i],end=" ")
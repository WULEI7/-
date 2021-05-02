a=[0]+[int(i) for i in input().split(" ")]
n=len(a)-1
ans,temp,left,right,tl,tr=0,0,0,0,0,0
for i in range(1,n+1):
    if temp>0:
        temp+=a[i]
        tr=i
    else:
        temp=a[i]
        tl=tr=i
    if temp>ans:
        ans=temp
        left=tl
        right=tr
print(ans,left,right,sep="\n")
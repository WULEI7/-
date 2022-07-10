import math
import numpy as np
data=list(map(int,input().split()))
len=int(math.sqrt(len(data)))
k=int(len/2)
d=np.array(data)
d.resize(len,len)
r=int(input())
c=int(input())
temp=[]
s=2
for i in range(0,len,s):
    for j in range(0,len,s):
        p=d[i:i+s,j:j+s].max()
        temp.append(p)
ans=np.array(temp)
ans.resize(k,k)
print(ans[r][c])

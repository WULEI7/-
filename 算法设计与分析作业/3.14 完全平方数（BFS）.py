from queue import *
from math import *

class state:
    temp=0
    step=0
    vec=[]

n=int(input())
ans=0
list=[]
num=int(sqrt(n))
a=[i*i for i in range(1,num+1)]
q=Queue()
for i in range(num):
    t=state()
    t.temp=a[i]
    t.step=1
    t.vec=[]
    t.vec.append(a[i])
    q.put(t)
while not q.empty():
    s=q.get()
    if(s.temp==n):
        ans=s.step
        list=s.vec[:]
        break
    for i in range(num):
        if(s.temp+a[i]<=n):
            t=state()
            t.temp=s.temp+a[i]
            t.step=s.step+1
            t.vec=s.vec[:]
            t.vec.append(a[i])
            q.put(t)
print(ans)
len=len(list)
#print(n,"=",list[0])
print("{}={}".format(n,list[0]),end="")
for i in range(1,len):
    #print("+",list[i])
    print("+{}".format(list[i]),end="")
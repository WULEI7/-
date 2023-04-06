n,k=map(int,input().split(" "))
s=1
num=0
mod=1e10
for i in range(1,n+1):
    s*=i
    while(s%10==0):
        num=num+1
        s=s//10
    s=s%mod
s="0000000000"+str(int(s))
len=len(s)
for i in range(len-k,len):
    print(s[i],end="")
print(" ",num,sep="")
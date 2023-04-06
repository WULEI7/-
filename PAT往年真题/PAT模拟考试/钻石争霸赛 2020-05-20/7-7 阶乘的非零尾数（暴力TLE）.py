n,k=map(int,input().split(" "))
s=1
for i in range(1,n+1):
    s*=i
s=str(s)
len=len(s)
print("长度为",len)
num=0
for pos in range(len-1,0,-1):
    if(s[pos]=='0'):
        num=num+1
    else:
        break
for i in range(pos-k+1,pos+1):
    print(s[i],end="")
print(" ",num,sep="")
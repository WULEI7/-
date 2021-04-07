n=int(input())
cnt1,cnt2=0,0
for i in range(n):
    a=int(input())
    if a>=60:
        cnt1+=1
    if a>=85:
        cnt2+=1
per1,per2=cnt1/n*100,cnt2/n*100
if per1-int(per1)<0.5:
    print(int(per1),"%",sep="")
else:
    print(int(per1)+1,"%",sep="")
if per2-int(per2)<0.5:
    print(int(per2),"%",sep="")
else:
    print(int(per2)+1,"%",sep="")
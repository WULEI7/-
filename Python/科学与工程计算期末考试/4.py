import datetime
data=[]
for i in range(8):
    d=list(input().split())
    data.append(d)
y1,m1,d1=input().split("-")
y2,m2,d2=input().split("-")
start=datetime.date(int(y1),int(m1),int(d1))
end=datetime.date(int(y2),int(m2),int(d2))
datelist=[]
for i in data:
    t=i[0]
    ty,tm,td=t.split("-")
    temp=datetime.date(int(ty),int(tm),int(td))
    datelist.append(temp)
sum=0.0
for i in range(len(datelist)):
    if datelist[i].__ge__(start) == True and datelist[i].__le__(end) == True:
        sum+=float(data[i][1])
print("%.2f"%sum)

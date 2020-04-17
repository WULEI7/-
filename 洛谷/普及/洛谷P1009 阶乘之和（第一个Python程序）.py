n=int(input())
temp=1
summ=0
for i in range (1,n+1):
    temp*=i
    summ+=temp
print(summ)

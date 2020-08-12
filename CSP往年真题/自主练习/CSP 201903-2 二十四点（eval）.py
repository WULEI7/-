n=int(input().strip())
for i in range(n):
    temp=input().strip()
    temp=temp.replace("/","//")
    temp=temp.replace("x","*")
    if eval(temp)==24:
        print("Yes")

    else:
        print("No")

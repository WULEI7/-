T=int(input())
for t in range(T):
    str1,str2=input().split(" ")
    a=int(str1,16)
    b=int(str2,16)
    while a!=b :
        if a>b : a=a//2
        else: b=b//2
    #print("Case #%d: %s\n"%(t+1,hex(a)[2:]))
    print("Case #{}: {}\n".format(t+1,hex(a)[2:]))
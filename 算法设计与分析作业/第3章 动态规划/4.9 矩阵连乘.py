def MatrixChain(p,n,m,s):
    for i in range(1,n+1):
        m[i][i]=0
    for r in range(2,n+1):
        for i in range(1,n-r+2):
            j=i+r-1
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j]
            s[i][j]=i
            for k in range(i+1,j):
                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]
                if t<m[i][j]:
                    m[i][j]=t
                    s[i][j]=k

def Traceback(i,j,s):
    if i==j:
        print("A",i,sep="",end="")
        return
    print("(",end="")
    Traceback(i,s[i][j],s)
    Traceback(s[i][j]+1,j,s)
    print(")",end="")

p=[int(i) for i in input().split(" ")]
n=len(p)-1
m=[[0 for i in range(n+1)] for j in range(n+1)]
s=[[0 for i in range(n+1)] for j in range(n+1)]
MatrixChain(p,n,m,s)
print(m[1][n])
Traceback(1,n,s)
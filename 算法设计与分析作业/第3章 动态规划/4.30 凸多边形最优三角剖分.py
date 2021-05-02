from math import *

def Weight(i, j, k):  # 权函数，此处为最小弦长三角剖分
    return w[i][j] + w[i][k] + w[j][k]

def MinWeightTriangulation(n, m, s):  # 计算最优值，注意此处的n为顶点个数，比书上n的大1
    for i in range(1, n):
        m[i][i] = 0
        s[i][i] = 0
    for r in range(2, n):
        for i in range(1, n - r + 1):
            j = i + r - 1
            m[i][j] = m[i + 1][j] + Weight(i - 1, i, j)
            s[i][j] = i
            for k in range(i + 1, j):
                t = m[i][k] + m[k + 1][j] + Weight(i - 1, k, j)
                if t < m[i][j]:
                    m[i][j] = t
                    s[i][j] = k

def Traceback(i, j, s):  # 构造最优三角剖分
    if i == j:
        return
    Traceback(i, s[i][j], s)
    Traceback(s[i][j] + 1, j, s)
    print(str(i - 1) + str(s[i][j]) + str(j))

n = int(input())
px, py = list(), list()
for i in range(n):
    x,y = map(int,input().split(" "))
    px.append(x)
    py.append(y)
w = [[0 for i in range(n)] for j in range(n)]
m = [[0 for i in range(n)] for j in range(n)]
s = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(i + 1, n):
        disx = px[i] - px[j]
        disy = py[i] - py[j]
        w[i][j] = int(sqrt(disx ** 2 + disy ** 2))  # 顶点i到顶点j的距离
MinWeightTriangulation(n, m, s)  # 计算最优值
Traceback(1, n - 1, s)  # 构造最优三角剖分

import numpy as np
import math

def min_weight(n, m, s, weights):  # 计算最优值并记录最优决策
    for i in range(1, n):
        m[i][i] = 0
        s[i][i] = 0
    for r in range(2, n):
        for i in range(1, n-r+1):
            j = i+r-1
            m[i][j] = m[i+1][j]+weights[i-1][i]+weights[i][j]+weights[j][i-1]  # get_weight(i-1, i, j)
            s[i][j] = i
            for k in range(i+1, j):
                t = m[i][k]+m[k+1][j]+weights[i-1][k]+weights[k][j]+weights[j][i-1]  # get_weight(i-1, k, j)
                if t < m[i][j]:
                    m[i][j] = t
                    s[i][j] = k

def traceback(i, j, s):
    if i == j:
        return
    traceback(i, int(s[i][j]), s)
    traceback(int(s[i][j] + 1), j, s)
    print(str(i-1)+str(s[i][j])+str(j))

def main():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))
    weights = np.zeros((n, n), dtype=int)
    for i in range(n):
        weights[i][i] = 0
    for i in range(n):
        for j in range(i+1, n):
            x = a[i][0]-a[j][0]
            y = a[i][1]-a[j][1]
            weights[i][j] = weights[j][i] = math.sqrt((x**2)+(y**2))
    # print(weights)
    m = np.zeros((n, n), dtype=int)  # 存放最优值
    s = np.zeros((n, n), dtype=int)  # 存放最优决策
    min_weight(n, m, s, weights)
    traceback(1, n-1, s)

if __name__ == '__main__':
    main()

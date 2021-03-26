def devide(lr,lc,tr,tc,size): # 分治，参数分别为：左上角位置所在行和列、已覆盖位置所在行和列、当前棋盘大小
    global num # 全局变量
    if size == 1:
        return
    s = size // 2 # 当前棋盘大小，注意：Python中整除必须用“//”
    no = num + 1 # 当前骨牌数字
    num += 1

    if tr < lr + s and tc < lc + s:
        devide(lr, lc, tr, tc, s)
    else:
        qp[lr + s - 1][lc + s - 1] = no
        devide(lr, lc, lr + s - 1, lc + s - 1, s) # 左上角棋盘

    if tr < lr + s and tc >= lc + s:
        devide(lr, lc + s, tr, tc, s)
    else:
        qp[lr + s - 1][lc + s] = no
        devide(lr, lc + s, lr + s - 1, lc + s, s) # 右上角棋盘

    if tr >= lr + s and tc < lc + s:
        devide(lr + s, lc, tr, tc, s)
    else:
        qp[lr + s][lc + s - 1] = no
        devide(lr + s, lc, lr + s, lc + s - 1, s) # 左下角棋盘

    if tr >= lr + s and tc >= lc + s:
        devide(lr + s, lc + s, tr, tc, s)
    else:
        qp[lr + s][lc + s] = no
        devide(lr + s, lc + s, lr + s, lc + s, s) # 右下角棋盘

k=int(input())
m,n=map(int,input().split())
t,num=0,0
if k == 2:
    t=4
if k == 3:
    t=8
qp=[[0 for i in range(t)] for j in range(t)] # 注意二维列表初始化的方法，防止下标越界
qp[m - 1][n - 1] = -1
devide(0, 0, m - 1, n - 1, t)
for i in range(t):
    for j in range(t):
        print(qp[i][j],end=" ")
    print("") # 注意缩进位置
def Maxsum(left, right, ansl, ansr):
    l1, r1, l2, r2, l3, r3 = 1, 1, 1, 1, 1, 1
    if left == right:
        if a[left] > 0:
            ansl, ansr = left
            return a[left]
        else:
            return 0
    else:
        mid = left + (right - left) // 2
        sum1 = Maxsum(left, mid, l1, r1)  # 情况1：最大子段与左半部分相同
        sum2 = Maxsum(mid + 1, right, l2, r2)  # 情况2：最大子段与右半部分相同
        sum3, s1, s2, temp1, temp2 = 0, 0, 0, 0, 0  # 情况3：最大子段跨越左右两个部分
        for i in range(mid, left - 1, -1):
            temp1 += a[i]
            if temp1 > s1:
                s1 = temp1
                l3 = i
        for i in range(mid + 1, right + 1):
            temp2 += a[i]
            if temp2 > s2:
                s2 = temp2
                r3 = i
        sum3 = s1 + s2
        ansl = l3
        ansr = r3
        if sum3 <= sum1:
            sum3 = sum1
            ansl = l1
            ansr = r1
        if sum3 <= sum2:  # 细节：这里要用<=
            sum3 = sum2
            ansl = l2
            ansr = r2
        return sum3  # 最大子段优先选择：左>中>右

a=[0]+[int(i) for i in input().split(" ")]
n=len(a)-1
ans=Maxsum(1,n)
ansl, ansr=0,0

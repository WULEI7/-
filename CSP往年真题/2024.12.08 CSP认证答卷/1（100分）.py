n, k = map(int, input().split())
while k > 0:
    x, y, s = input().split()
    x, y = int(x), int(y)
    len_s = len(s)
    for i in range(len_s):
        if s[i] == 'f':
            if y + 1 <= n:
                y += 1
        elif s[i] == 'b':
            if y - 1 >= 1:
                y -= 1
        elif s[i] == 'r':
            if x + 1 <= n:
                x += 1
        elif s[i] == 'l':
            if x - 1 >= 1:
                x -= 1
    print(x, y)
    k -= 1
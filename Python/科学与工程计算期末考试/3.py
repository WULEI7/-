max = 0
day = 0
for i in range(1, 8):
    a, b = map(int, input().split())
    s = a + b
    if s > max and s > 8:
        max = s
        day = i
print(day)

ss = input().split()
word = sorted(set(ss))
for i in word:
    print("{0}:{1}".format(i, ss.count(i)))

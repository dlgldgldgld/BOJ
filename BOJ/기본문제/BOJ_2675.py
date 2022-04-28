from sys import stdin

n = int(stdin.readline())
for _ in range(n):
    r, s = stdin.readline().rstrip().split(" ")
    r = int(r)
    for a in s:
        for _ in range(r):
            print(a, end="")
    print()

from sys import stdin
from bisect import bisect_left, bisect_right

n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
a.sort()

m = int(stdin.readline())
b = list(map(int, stdin.readline().split()))

for val in b :
    l = bisect_left(a, val)
    r = bisect_right(a, val)
    if l == r :
        print(0, end=" ")
    else :
        print(1, end=" ")

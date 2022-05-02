from sys import stdin
from heapq import heappush, heappop
n = int(stdin.readline())

h = []
for _ in range(n):
    a = int(stdin.readline())
    if a == 0 :
        k = 0
        if len(h):
            k = heappop(h)[1]
        print(k)
    else :
        heappush(h, (-a, a))
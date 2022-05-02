from heapq import heappush, heappop
from sys import stdin
l = []
n = int(stdin.readline())
for _ in range(n):
    node = int(stdin.readline())
    if node == 0:
        if len(l) > 0:
            print(heappop(l)[1])
        else:
            print(0)
    else:
        heappush(l, (abs(node), node))
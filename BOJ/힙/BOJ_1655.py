from sys import stdin, stdout
from heapq import heappush, heappop

maxheap = []
minheap = []

n = int(stdin.readline())
for _ in range(n):
    node = int(stdin.readline())
    if len(maxheap) == len(minheap):
        heappush(maxheap, (-node, node))
    elif len(maxheap) == len(minheap) + 1:
        heappush(minheap, node)

    if maxheap and minheap:
        if maxheap[0][1] > minheap[0]:
            a = heappop(maxheap)
            b = heappop(minheap)
            heappush(minheap, a[1])
            heappush(maxheap, (-b, b))
    stdout.write(str(maxheap[0][1]) + "\n")
from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
n, k = map(int, input().split())

que = [[0, n]]
dist = [1e9] * (100001)
dist[n] = 0
while que:
    w, curr = heappop(que)
    if dist[curr] < w:
        continue

    if (curr - 1) >= 0 and dist[curr - 1] > w + 1:
        dist[curr - 1] = w + 1
        heappush(que, [w + 1, curr - 1])
    if (curr + 1) <= 100000 and dist[curr + 1] > w + 1:
        dist[curr + 1] = w + 1
        heappush(que, [w + 1, curr + 1])
    if curr * 2 <= 100000 and dist[curr * 2] > w:
        dist[curr * 2] = w
        heappush(que, [w, 2 * curr])

print(dist[k])

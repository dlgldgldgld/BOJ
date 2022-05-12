from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
# input = open("input.txt", "r").readline
n, m, k, x = map(int, input().split())
edge = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    edge[a].append([b, 1])

dist = [1e9] * (n + 1)
dist[x] = 0
que = [[0, x]]

while que:
    dis, curr = heappop(que)
    if dist[curr] < dis:
        continue
    for next, next_dis in edge[curr]:
        new_dis = next_dis + dis
        if dist[next] > new_dis and new_dis <= k:
            dist[next] = new_dis
            heappush(que, [new_dis, next])

is_answer = False
for i in range(1, n + 1):
    if dist[i] == k:
        is_answer = True
        print(i)

if is_answer == False:
    print(-1)

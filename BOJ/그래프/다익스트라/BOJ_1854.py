from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
f = open("input.txt", "r")
input = f.readline
n, m, k = map(int, input().split())

dist = [1e9] * (n + 1)
edge = [[] for _ in range(n + 1)]

for _ in range(m):
    s, d, w = map(int, input().split())
    edge[s].append([d, w])

que = [[0, 1]]
n_que = [[] for _ in range(n + 1)]
n_que[1] = [0]
call = 0
while que:
    c_dist, curr = heappop(que)
    call += 1
    for next, weight in edge[curr]:
        next_weight = c_dist + weight
        if len(n_que[next]) < k:
            heappush(n_que[next], -next_weight)
            heappush(que, [next_weight, next])
        elif -n_que[next][0] > next_weight:
            heappop(n_que[next])
            heappush(n_que[next], -next_weight)
            heappush(que, [next_weight, next])

for i in range(1, n + 1):
    if len(n_que[i]) < k:
        print(-1)
    else:
        print(-n_que[i][0])

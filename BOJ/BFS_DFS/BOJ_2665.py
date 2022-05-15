from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
n = int(input())
room = []
for _ in range(n):
    room.append(list(map(int, input().strip())))

visit = [[False]*50 for _ in range(50)]
que = [[0, 0, 0]]
visit[0][0] = True

d_x = [-1, 0, 1, 0]
d_y = [0, 1, 0, -1]
while que:
    broken_wall, x, y = heappop(que)
    if x == n-1 and y == n-1:
        print(broken_wall)
        break
    for i in range(4):
        n_x = x + d_x[i]
        n_y = y + d_y[i]
        if n_y < 0 or n_x < 0 or n_y > n-1 or n_x > n-1:
            continue
        if visit[n_y][n_x] == True:
            continue
        if room[n_y][n_x] == 0:
            visit[n_y][n_x] = True
            heappush(que, [broken_wall+1, n_x, n_y])
        else :
            visit[n_y][n_x] = True
            heappush(que, [broken_wall, n_x, n_y])


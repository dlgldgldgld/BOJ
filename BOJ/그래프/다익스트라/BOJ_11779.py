from sys import stdin
from heapq import heappush, heappop

n = int(stdin.readline())
m = int(stdin.readline())
edge = [[] for i in range(n+1)]
for _ in range(m):
    a, b, c = map(int, stdin.readline().split())
    edge[a].append([b,c])
    
st, ed = map(int, stdin.readline().split())

dist = [1e9]*(n+1)
visited = [False]*(n+1)
roads = [-1]*(n+1)
que = []

dist[st] = 0

heappush(que, [0, st])

while que:
    dis, curr = heappop(que)
    if visited[curr] :
        continue
    visited[curr] = True
    for next, val in edge[curr]:
        n_dis = dis + val
        if dist[next] > n_dis :
            dist[next] = n_dis 
            roads[next] = curr
            heappush(que, [n_dis, next])

end = ed
answer = []
answer.append(end)
while roads[end] != -1:
    end = roads[end]
    answer.append(end)

print(dist[ed])
print(len(answer))
print(" ".join( str(i) for i in answer[::-1]))

# print(len(answer))
# print(" ".join( str(i) for i in answer[::-1]))
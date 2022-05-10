# 1. 최초의 최단거리 경로를 찾음 ( N*LogN)
# 2. 최단경로의 edge들을 모두 제거함.
# 3. 다시 최단거리 경로를 찾음.
# 4. 값 출력 ( 경로를 찾지 못할시 -1 )
from heapq import heappush, heappop
from collections import deque

from sys import stdin, stdout

def daijkstra(n, s, d, vis = None):
    if vis :
        visited_1 = [[False]*n for _ in range(n)]
        q = deque([d])
        while q:
            node = q.popleft()
            for adj_node in vis[node]:
                if not visited_1[adj_node][node]:
                    edges[adj_node] = list(filter(lambda x:x[0] != node, edges[adj_node]))
                    visited_1[adj_node][node] = True
                    q.append(adj_node)
    
    visited = [[] for _ in range(n)]
    dist = [1e9]*n
    dist[s] = 0
    que = [[0, s]]

    while(que):
        dis, curr = heappop(que)
        if dis > dist[curr]:
            continue
        for [next, next_dis] in edges[curr]:
            new_dis = dis + next_dis
            if dist[next] > new_dis:
                dist[next] = new_dis
                visited[next] = [curr]
                heappush(que, [new_dis, next])
            elif dist[next] == new_dis:
                visited[next].append(curr)

    return visited, dist[d]

def solution(n, s, d):
    visit1, min_dis = daijkstra(n, s, d)
    _, min_dis = daijkstra(n, s, d, visit1)
    if min_dis == 1e9:
        stdout.write('-1' + '\n')
    else :
        stdout.write(str(min_dis) + '\n')

while True :
    n, m = map(int, stdin.readline().split())
    if n == 0 and m == 0:
        break
    s, d = map(int, stdin.readline().split())
    edges = [[] for _ in range(n)]
    for _ in range(m):
        n1, n2, w = map(int, stdin.readline().split())
        edges[n1].append([n2, w])

    solution(n, s, d)

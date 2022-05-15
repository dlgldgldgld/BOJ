from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
# input = open("input.txt","r").readline

t = int(input())
for _ in range(t):
    n,d,c= map(int, input().split())
    edge = [[] for _ in range(n+1)]
    for _ in range(d):
        a,b,s = map(int, input().split())
        edge[b].append([a,s])

    dist = [1e9] * (n+1)
    dist[c] = 0

    que = [[0, c]]
    while que :
        second, curr = heappop(que)
        for next, next_second in edge[curr]:
            new_second = second + next_second
            if dist[next] > new_second :
                dist[next] = new_second
                heappush(que, [new_second, next])

    ans = list(filter(lambda x : ( x != 1e9 ) , dist))
    print(len(ans), max(ans))
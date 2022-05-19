from sys import stdin, setrecursionlimit
setrecursionlimit(int(1e6))

input = stdin.readline
# input = open("input.txt", "r").readline

v, e = map(int, input().split())
parent = [-1] * (v+1)
edges = []

def find(n):
    if parent[n] == -1:
        return n
    parent[n] = find(parent[n])
    return parent[n]

def merge(a, b):
    pa = find(a)
    pb = find(b)
    if pa == pb :
        return 
    if pa > pb : 
        pa, pb = pb, pa
    parent[pb] = pa
    return 

for _ in range(e):
    a, b, c = map(int, input().split())
    edges.append([a, b, c])

edges.sort(key=lambda x : x[2])
answer = 0
merge_edge = 0
for st, ed, w in edges:
    if merge_edge == v-1:
        break
    if find(st) == find(ed) :
        continue
    answer += w
    merge_edge += 1
    merge(st, ed)

print(answer)
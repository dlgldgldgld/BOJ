from sys import stdin, setrecursionlimit
setrecursionlimit(int(1e6))

input = stdin.readline
# input = open("input.txt", "r").readline

n, m = map(int, input().split())
p = [-1] * (n+1)
edges = []

def find(n):
    if p[n] == -1:
        return n
    p[n] = find(p[n])
    return p[n]

def merge(pa, pb):
    if pa > pb :
        pa, pb = pb, pa
    p[pb] = pa
    return    

for _ in range(m):
    st, ed, w = map(int, input().split())
    edges.append([st, ed, w])

edges.sort(key = lambda x : x[2])
answer = 0
e_cnt = 0
for st, ed, w in edges :
    if e_cnt == n-2 :
        break
    pst = find(st)
    ped = find(ed)
    if pst == ped:
        continue
    
    answer += w
    e_cnt += 1
    merge(pst, ped)

print(answer)
from sys import stdin, setrecursionlimit
setrecursionlimit(int(1e6))
input = stdin.readline
# input = open('input.txt','r').readline

n = int(input())
pos = []
p = [-1] * (n+1)
def get_edge(pos_info, i, k):
    st = pos_info[i][0]
    ed = pos_info[i+1][0]
    w  = abs(pos_info[i][k] - pos_info[i+1][k])
    return [st, ed, w]

def find(n):
    if p[n] == -1:
        return n
    p[n] = find(p[n])
    return p[n]

def merge(pa, pb):
    if pa > pb:
        pa, pb = pb, pa
    p[pb] = pa
    return True

for i in range(1, n+1):
    x, y, z = map(int, input().split())
    pos.append([i,x,y,z])

x_pos = sorted(pos, key = lambda x : x[1])
y_pos = sorted(pos, key = lambda x : x[2])
z_pos = sorted(pos, key = lambda x : x[3])

edges = []
for i in range(n-1):
    edges.append(get_edge(x_pos, i, 1))
    edges.append(get_edge(y_pos, i, 2))
    edges.append(get_edge(z_pos, i, 3))

edges.sort(key=lambda x : x[2])
answer = 0
merge_cnt = 0
for st, ed, w in edges:
    if merge_cnt == n-1:
        break
    pst = find(st)
    ped = find(ed)
    if pst == ped :
        continue
    merge(pst, ped)
    answer += w
    merge_cnt += 1

print(answer)
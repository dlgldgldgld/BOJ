from sys import stdin, setrecursionlimit
from math import sqrt
from decimal import Decimal
setrecursionlimit(pow(10,6))

input = stdin.readline
# input = open('input.txt', 'r').readline

n = int(input())
stars = []
p = [-1] * (n+1)

def find(n):
    if p[n] == -1:
        return n
    p[n] = find(p[n])
    return p[n]

def merge(pa, pb):
    if pa == pb :
        return
    if pa > pb :
        pa, pb = pb, pa
    p[pb] = pa
    return

for i in range(n):
    a, b = map(Decimal, input().split())
    stars.append([i+1, a, b])

edges = []
for star1 in stars:
    for star2 in stars:
        if star1 == star2 :
            continue
        w = sqrt(pow(star2[1] - star1[1], 2) + pow(star2[2] - star1[2],2))
        edges.append([star1[0], star2[0], w])

edges.sort(key=lambda x : x[2])
ans = 0
e_cnt = 0
for st, ed, w in edges:
    if e_cnt == n-1:
        break
    pst = find(st)
    ped = find(ed)
    if pst == ped :
        continue
    ans += w
    e_cnt += 1
    merge(pst, ped)

print(f'{ans:.2f}')
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(int(1e6))

input = stdin.readline
# input = open('input.txt','r').readline

t = int(input())

def find(n, p):
    if p[n] < 0:
        return n
    p[n] = find(p[n], p)
    return p[n]

def merge(a, b, p):
    pa = find(a, p)
    pb = find(b, p)
    if pa == pb :
        return abs(p[pb])

    p[pb] += p[pa]
    p[pa] = pb
    return abs(p[pb])

for _ in range(t):
    f_list = dict()
    n = int(input())
    p = [-1] * 200001
    for _ in range(n):
        a, b = input().split()
        a_idx = f_list.setdefault(a, len(f_list))
        b_idx = f_list.setdefault(b, len(f_list))
        stdout.write(str(merge(a_idx, b_idx, p)) + '\n')
        
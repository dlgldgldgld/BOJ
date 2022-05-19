from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(int(1e6))
input = stdin.readline
# input = open('input.txt','r').readline

n, m = map(int, input().split())
p = [-1]*(n+1)

def find(n):
    if p[n] == -1:
        return n
    p[n] = find(p[n])
    return p[n]

def merge(a,b, is_merge = False):
    pa = find(a)
    pb = find(b)
    if pa == pb :
        return True
    if is_merge :
        p[pb] = pa
    return False

for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 0 :
        merge(b,c,True)
        pass
    elif a == 1 :
        stdout.write('YES\n') if merge(b,c) else stdout.write('NO\n')
        pass
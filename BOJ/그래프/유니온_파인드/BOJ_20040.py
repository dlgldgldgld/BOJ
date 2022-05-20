from sys import stdin, setrecursionlimit
setrecursionlimit(pow(10,6))

input = stdin.readline 
# input = open('input.txt','r').readline

def find(n):
    if p[n] == -1:
        return n
    p[n] = find(p[n])
    return p[n]

def merge(a, b):
    pa = find(a)
    pb = find(b)
    if pa == pb :
        return False
    if pa > pb :
        pa, pb = pb, pa
    p[pb] = pa
    return True

n, m = map(int, input().split())
p = [-1] * (n+1)
ans = 0
for i in range(m):
    a, b = map(int, input().split())
    if False == merge(a, b):
        ans = i+1
        break

print(ans)

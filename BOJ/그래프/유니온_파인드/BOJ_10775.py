from sys import stdin, setrecursionlimit
setrecursionlimit(pow(10,6))

input = stdin.readline
# input = open('input.txt','r').readline

def find(n):
    if parent[n] == -1:
        return n
    parent[n] = find(parent[n])
    return parent[n]

g = int(input())
p = int(input())
parent = [-1] * (g+1)
answer = 0
for i in range(p):
    pi = int(input())
    if parent[pi] == -1:
        parent[pi] = find(pi-1)
    else :
        p_idx = find(pi-1)
        if p_idx == 0:
            answer = i
            break
        if parent[p_idx] == -1:
            parent[p_idx] = find(p_idx-1)

print(answer) if answer != 0 else print(p)
    
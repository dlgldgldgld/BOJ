from math import log2, ceil
from sys import stdin, stdout

input = stdin.readline
# input = open('input.txt', 'r').readline

node_cnt = pow(2,ceil(log2(2000000)))
db = [0]*(node_cnt*2)

def update(idx):
    n_idx = node_cnt + idx
    while n_idx > 0:
        n_idx = n_idx // 2
        db[n_idx] = db[n_idx*2] + db[n_idx*2 + 1] 

def query(rank, node_idx, n_l, n_r):
    if n_l == n_r :
        stdout.write(str(node_idx - node_cnt) + '\n')
        db[node_idx] -= 1
        update(node_idx - node_cnt)
        return 
    if n_r < n_l :
        return 

    middle = ( n_l + n_r ) // 2
    if db[node_idx*2] >= rank :
        query(rank, node_idx*2, n_l, middle) 
    else :
        query(rank - db[node_idx*2], node_idx*2 + 1, middle + 1, n_r)


n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    if a == 1:
        db[node_cnt + b] += 1
        update(b)
    else :
        query(b, 1, 1, node_cnt)
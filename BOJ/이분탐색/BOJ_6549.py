from sys import stdin, stdout, setrecursionlimit
from math import log2, ceil
setrecursionlimit(int(1e5))
input = stdin.readline
# input = open('input.txt','r').readline

def update(idx, val):
    n_idx = node_cnt + idx
    min_tree[n_idx] = [val, idx+1]
    while n_idx > 0:
        n_idx //= 2
        if min_tree[n_idx*2][0] > min_tree[n_idx*2 + 1][0] :
            min_tree[n_idx] = min_tree[n_idx*2 + 1]
        else :
            min_tree[n_idx] = min_tree[n_idx*2]

def find_min(ql, qr, n_idx, nl, nr):
    if ql <= nl and nr <= qr :
        return min_tree[n_idx]
    if ql > nr or qr < nl :
        return [ int(1e9+1) , -1]

    middle = (nl + nr) // 2
    return min(
            find_min(ql, qr, n_idx*2, nl, middle), 
            find_min(ql, qr, n_idx*2 + 1, middle + 1, nr) 
        )

def find_ans(ql, qr):
    if ql > qr :
        return 0

    min_node = find_min(ql, qr, 1, 1, node_cnt)
    m_val, m_idx = min_node
    m_val = (qr-ql+1) * m_val
    res = m_val
    if ql <= m_idx-1:
        res = max(res, find_ans(ql, m_idx-1))
    if m_idx+1 <= qr:
        res = max(res, find_ans(m_idx+1, qr))
    
    return res

while True:
    n, *histogram = list(map(int, input().split()))
    if n == 0:
        break
    node_cnt = pow(2, ceil(log2(n)))
    min_tree = [[int(1e9+1), -1]] * (node_cnt*2+1)
    for idx, val in enumerate(histogram):
        update(idx, val)
    stdout.write(str(find_ans(1, n)) + '\n')
    
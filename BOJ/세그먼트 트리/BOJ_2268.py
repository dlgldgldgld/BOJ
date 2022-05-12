from sys import stdin, stdout
input = stdin.readline
# input = open("input.txt", "r").readline
def insert(idx, val):
    n_idx = node_cnt + idx
    node[n_idx] = val
    while n_idx > 0:
        n_idx //= 2
        node[n_idx] = node[n_idx*2] + node[n_idx*2 + 1]

def get_query(q_l, q_r, node_idx, n_l, n_r):
    if q_l <= n_l and n_r <= q_r:
        return node[node_idx]
    if q_l > n_r or q_r < n_l :
        return 0

    middle = (n_l + n_r) // 2
    return get_query(q_l, q_r, node_idx*2, n_l, middle) + get_query(q_l, q_r, node_idx*2 + 1, middle+1, n_r)

n, m = map(int, input().split())
depth = 0
while pow(2, depth) < n:
    depth += 1

node_cnt = pow(2, depth)
node = [0] * (2*node_cnt+1)

for _ in range(m):
    a,b,c = map(int, input().split())
    
    if a == 1:
        insert(b-1,c)
    else :
        if b > c :
            b, c = c, b
            
        stdout.write(str(get_query(b,c,1,1,node_cnt)) + "\n")
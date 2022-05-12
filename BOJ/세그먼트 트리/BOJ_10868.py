from sys import stdin
input = stdin.readline
# input = open("input.txt","r").readline
def insert( i, val ):
    curr_idx = i+base_node
    node[curr_idx] = val
    while(curr_idx > 0):
        curr_idx = curr_idx // 2
        node[curr_idx] = min(node[curr_idx*2], node[curr_idx*2 + 1])
    return

def getquery( q_l, q_r, node_idx, n_l, n_r):
    if q_l <= n_l and n_r <= q_r :
        return node[node_idx]
    
    if n_r < q_l or n_l > q_r :
        return 1e9 + 1

    middle = (n_l + n_r) // 2
    return min(getquery(q_l, q_r, node_idx*2, n_l, middle), getquery(q_l, q_r, node_idx*2 + 1, middle+1, n_r))

n, m = map(int, input().split())

node = [1e9 + 1] * 262144
depth = 0
while pow(2, depth) < n:
    depth += 1

base_node = pow(2, depth)
for i in range(n):
    insert(i, int(input())) 

for _ in range(m):
    q_l, q_r = map(int, input().split())
    print(getquery(q_l, q_r, 1, 1, base_node))


from sys import stdin, stdout

node = [0] * 2097152


def update(idx, value):
    c_idx = idx + node_cnt
    node[c_idx] = value

    while (c_idx := c_idx // 2) > 0:
        node[c_idx] = node[c_idx * 2] + node[c_idx * 2 + 1]
    return


def get(l, r, node_idx, node_l, node_r):
    if l > node_r or r < node_l:
        return 0
    if l <= node_l and node_r <= r:
        return node[node_idx]

    middle = (node_l + node_r) // 2
    return get(l, r, node_idx * 2, node_l, middle) + get(
        l, r, node_idx * 2 + 1, middle + 1, node_r
    )


# f = open("input.txt", "r")
# input = f.readline
input = stdin.readline

n, m, k = map(int, input().split())
depth = 0
temp_n = n
while temp_n > 0:
    depth += 1
    temp_n = temp_n // 2

node_cnt = pow(2, depth)
for i in range(0, n):
    update(i, int(input()))

for _ in range(0, m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        # update
        update(b - 1, c)
    elif a == 2:
        # query
        stdout.write(str(get(b, c, 1, 1, node_cnt)) + "\n")

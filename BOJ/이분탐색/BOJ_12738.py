from bisect import bisect_left

n = int(input())
a = list(map(int, input().split()))
tree = []

for i in a :
    f_idx = bisect_left(tree, i)
    if len(tree) == f_idx:
        tree.append(i)
    else :
        tree[f_idx] = i

print(len(tree))
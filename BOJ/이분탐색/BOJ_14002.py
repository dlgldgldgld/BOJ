from bisect import bisect_left

n = int(input())
a = list(map(int, input().split()))
tree = []
a_idx = [-1] * n

for idx, val in enumerate(a) :
    f_idx = bisect_left(tree, val)
    a_idx[idx] = f_idx
    if len(tree) == f_idx:
        tree.append(val)
    else :
        tree[f_idx] = val

print(len(tree))
base = len(tree)-1
r_idx = n-1
ans = []
for aa in a_idx[::-1]:
    if aa == base :
        ans.append(a[r_idx])
        base -= 1
    r_idx -= 1

print(" ".join(str(t) for t in ans[::-1]))
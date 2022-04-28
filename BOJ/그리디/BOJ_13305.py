# 4
# 2 3 1
# 5 2 4 1

n = int(input())
d = list(map(int, input().split()))
g = list(map(int, input().split()))
answer = 0
curr_idx = 0
max_g = g[0]

for idx, val in enumerate(g[1:]):
    if max_g >= val:
        answer += sum(d[curr_idx : idx + 1]) * max_g
        max_g = val
        curr_idx = idx + 1

if curr_idx < n - 1:
    answer += sum(d[curr_idx:n]) * max_g

print(answer)

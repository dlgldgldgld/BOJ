from sys import stdin
input = stdin.readline

n = int(input())
db = dict()
for _ in range(n):
    a = int(input())
    db.setdefault(a, 0)
    db[a] += 1
    
ans = 0
max_val = 0
for key, val in db.items():
    if max_val < val:
        max_val = val
        ans = key
    elif max_val == val:
        ans = min(ans, key)

print(ans)

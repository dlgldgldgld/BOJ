n, ans = int(input()), 0
for i in range(1, n+1):
    s = sum([int(k) for k in str(i)])
    ans += 1 if i % s == 0 else 0
print(ans)
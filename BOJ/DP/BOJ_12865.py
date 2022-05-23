n, k = map(int, input().split())
bags = []
for _ in range(n):
    w, v = map(int, input().split())
    bags.append([w,v])

bags.sort()
dp = [[0]*(k+1) for _ in range(n)]

for i in range(n) :
    for j in range(k+1):
        weight, value = bags[i]
        if j - weight >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value)
        else :
            dp[i][j] = max(dp[i][j], dp[i-1][j])

print(dp[n-1][k])
        


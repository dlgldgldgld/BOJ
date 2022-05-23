from sys import stdin

input = stdin.readline

dp = [0] * (46)
dp[1], dp[2] = 1, 1
for i in range(3, 46):
    dp[i] = dp[i-1] + dp[i-2]

print(dp[int(input())])

dp = [0]*11
dp[1]= 1
for i in range(2, 11):
    dp[i] = i*dp[i-1]

n = int(input())
print(dp[n])
dp = [1] * 1001
dp[2] = 0
for i in range(2, 1001):
    if dp[i-1] == 1 and dp[i-3] == 1:
        dp[i] = 0

n = int(input())
if 1 == dp[n]:
    print('SK')
else :
    print('CY')


dp = [1] * 1001
dp[1] = 1

for i in range(2, 1001):
    if i == 2 :
        dp[i] = 0
        continue
    elif i == 3 :
        dp[i] = 1
        continue

    if dp[i-1] == 1 and dp[i-3] == 1:
        dp[i] = 0

n = int(input())
if 1 == dp[n]:
    print('SK')
else :
    print('CY')


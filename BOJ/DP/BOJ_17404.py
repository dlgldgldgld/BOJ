n = int(input())
rgbs = []
for i in range(n):
  rgbs.append(list(map(int, input().split(' '))))

dp = [[[1e9 for _ in range(3)] for _ in range(n+1)] for _ in range(3)]
# dp[fc][n][c] = fc에서 최초로 시작햇을때 n번째에서 c컬러일때 최소값.
dp[0][1][0], dp[1][1][1], dp[2][1][2] = rgbs[0][0], rgbs[0][1], rgbs[0][2]

for k in range(3):
    for i in range(2, n+1):
        dp[k][i][0] = rgbs[i-1][0] + min(dp[k][i-1][1], dp[k][i-1][2])
        dp[k][i][1] = rgbs[i-1][1] + min(dp[k][i-1][0], dp[k][i-1][2])
        dp[k][i][2] = rgbs[i-1][2] + min(dp[k][i-1][0], dp[k][i-1][1])
 
# 시작과 끝이 같은값은 존재할 수 없음.
dp[0][n][0], dp[1][n][1], dp[2][n][2] = 1e9, 1e9, 1e9
answer = 1e9
for i in range(3):
    answer = min(answer,dp[i][n][0], dp[i][n][1], dp[i][n][2])
print(answer)

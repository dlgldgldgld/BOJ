from sys import stdin

dp = [[[1] * 21 for _ in range(21)] for _ in range(21)]

for i in range(1, 21):
    for j in range(1, 21):
        for k in range(1, 21):
            if i< j and j < k:
                dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k]
            else :
                dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1]

while (True):
    i,j,k = map(int, stdin.readline().split())
    if i == -1 and j == -1 and k == -1:
        break
    
    answer = 1
    if i <= 0 or j <= 0 or k <= 0 :
        answer = 1
    elif i > 20 or j > 20 or k > 20:
        answer = dp[20][20][20]
    else:
        answer = dp[i][j][k]

    print(f"w({i}, {j}, {k}) = {answer}")

    

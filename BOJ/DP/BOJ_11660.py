from sys import stdin, stdout
input = stdin.readline

n, m = map(int, input().split())
board = []
dp    = [[0]*(n) for _ in range(n)]
for i in range(n):
    b = list(map(int, input().split()))
    board.append(b)

for i in range(n):
    for j in range(n):
        dp[i][j] = board[i][j]
        if i-1 >= 0:
            dp[i][j] += dp[i-1][j]
        if j-1 >= 0:
            dp[i][j] += dp[i][j-1]
        if j-1 >= 0 and i-1 >= 0 :
            dp[i][j] -= dp[i-1][j-1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    x1, y1, x2, y2 = x1-1, y1-1, x2-1, y2-1
    sum = dp[x2][y2] 
    if x1-1 >= 0:
        sum -= dp[x1-1][y2]
    if y1-1 >= 0:
        sum -= dp[x2][y1-1]
    if y1-1 >= 0 and x1-1 >= 0 :
        sum += dp[x1-1][y1-1]
    
    stdout.write(str(sum) + '\n')


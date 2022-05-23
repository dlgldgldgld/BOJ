n = int(input()) + 1
dp = [[0]*10 for _ in range(12)]

def get_ans(len, num, div, ans):
    if len == 0:
        print(ans)
        return
    ans += str(num)
    temp_div = 0
    for next_num in range(10):
        if temp_div + dp[len-1][next_num] >= div:
            break
        temp_div += dp[len-1][next_num]
    
    get_ans(len-1, next_num, div-temp_div, ans)
    return

for i in range(1, 12):
    for j in range(10):
        if i == 1:
            dp[i][j] = 1
        else :
            for k in range(0,j):
                dp[i][j] += dp[i-1][k]

temp = 0
is_find = False
for i in range(1,12):
    for j in range(10):
        if temp + dp[i][j] >= n :
            is_find = True
            break
        else :
            temp += dp[i][j]
    if is_find :
        break
if is_find == False :
    print(-1)
else:
    get_ans(i,j,n-temp,"")
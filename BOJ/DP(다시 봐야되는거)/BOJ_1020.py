dp = [[-1]*106 for _ in range(16)]
counter = [6,2,5,5,4,5,6,3,7,5]
        
# DP[N][S] = N자리를 움직여서 S를 만들수 있는 최소 움직여야하는 수
# DP[N+1][S] = DP[N][S]
                                   
#     +   +---+   +---+   +   +   +---+
#     |       |       |   |   |   |
#     +   +---+   +---+   +---+   +---+
#     |   |           |       |       |
#     +   +---+   +---+       +   +---+
#    (2)   (5)     (5)     (4)     (5)
# +---+   +---+   +---+   +---+   +---+
# |           |   |   |   |   |   |   |
# +---+       +   +---+   +---+   +   +
# |   |       |   |   |       |   |   |
# +---+       +   +---+       +   +---+
#   (6)     (3)     (7)     (5)    (6)

abc = "1"
input_timer = list(map(int, abc))[::-1]
input_number = int(abc)
all_sum = sum([counter[i] for i in input_timer])

for i in range(10):
    idx = (input_timer[0] + i) % 10
    if dp[0][counter[idx]] > 0:
        dp[0][counter[idx]] = min(dp[0][counter[idx]], i)
    else :
        dp[0][counter[idx]] = i

for i in range(len(input_timer)-1):
    for j in range(106):
        if dp[i][j] >= 0 :
            b_minus = False
            if ( input_number % pow(10, i + 1) ) + dp[i][j] >= pow(10, i + 1):
                b_minus = True
            for k in range(0, 10):
                c_k = ( input_timer[i+1] + k ) % 10
                c_k_v = counter[c_k]
                val = dp[i][j] + ( pow(10, i+1) * k )
                if b_minus :
                    val -= pow(10, i+1)
                if val <= 0 :
                    continue
                if dp[i+1][c_k_v + j] == -1:
                    dp[i+1][c_k_v + j] = val
                else :
                    dp[i+1][c_k_v + j] = min(dp[i+1][c_k_v + j], val)

if dp[len(input_timer)-1][all_sum] == 0:
    print(pow(10, len(input_timer)))
else :
    print(dp[len(input_timer)-1][all_sum])
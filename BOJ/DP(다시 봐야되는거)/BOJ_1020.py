dp = [[-1]*106 for _ in range(16)]
counter = [6,2,5,5,4,5,6,3,7,5]
        
# DP[N][S] = N자리를 움직여서 숫자 S를 만들 수 있는 최소 숫자
# DP[N][S] = for K in 1~9 바퀴 돌림 : DP[N-1][sum - counter[K+curr[N]]] + K * pow(10, N-1)
#            if DP[N-1][sum - counter[K+curr[N]]] + curr[N-1] > 10 : K*pow(10, N-1)은 안돌려도 됨.                                    

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

# setting
c_time = list(map(int,"1"))[::-1]
c_size = len(c_time)
c_sum = 0
for i in c_time:
    c_sum += counter[int(i)]

for n in range(c_size):
    n_number = c_time[n]
    for k in range(1, 11):
        idx = (c_time[n] + k) % 10
        if n == 0 :
            if dp[n][counter[idx]] == -1:
                dp[n][counter[idx]] = k
            else :
                dp[n][counter[idx]] = min(dp[n][counter[idx]], k)
        else :
            cc_sum = 0
            for j, val in enumerate(c_time[0:n]):
                cc_sum += val * pow(10,j)

            for s in range(1,106):
                if dp[n-1][s] > 0 :
                    val = dp[n-1][s] + pow(10,n) * k
                    if dp[n-1][s] + cc_sum > pow(10,n) :
                        val -= pow(10,n)

                    if dp[n][s+counter[idx]] == -1:
                        dp[n][s+counter[idx]] = val
                    else:
                        dp[n][s+counter[idx]] = min(dp[n][s+counter[idx]], val)
                

        # k 1, 2, 3

answer = 100000001
for n in range(c_size):
    a_sum = 0
    for j, val in enumerate(c_time[0:n]):
        a_sum += val * pow(10,j)
    
    if n == 0 :
        if dp[0][counter[c_time[n]]] > 0:
            if dp[0][counter[c_time[n]]] + c_time[n] >= 10 :
                if n == c_size - 1 :
                    answer = min(answer, dp[0][counter[c_time[n]]])
            else :
                answer = min(answer, dp[0][counter[c_time[n]]])
    else :
        cc_sum = 0
        for j in c_time[n+1:]:
            cc_sum += counter[j]
        
        for j in range(c_time[n], 11):
            j_idx = j % 10
            t_sum = c_sum - (cc_sum + counter[j_idx])
            if dp[n-1][t_sum] == -1 or t_sum < 0 :
                continue
            val = dp[n-1][t_sum] + (j-c_time[n]) * pow(10,n)
            answer = min(answer, val)
            
print(answer)
    

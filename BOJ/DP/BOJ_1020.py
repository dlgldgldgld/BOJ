counter = [6,2,5,5,4,5,6,3,7,5] 
def main(aaa):
    dp = [[-1]*106 for _ in range(16)]
    # DP[N][S] = N자리를 움직여서 S를 만들수 있는 최소 움직여야하는 수
    # DP[N+1][S] = DP[N][S]
    abc = aaa
    input_timer = list(map(int, abc))
    input_number = int(abc)

    for i in range(10):
        idx = i % 10    
        if dp[0][counter[idx]] >= 0:
            dp[0][counter[idx]] = min(dp[0][counter[idx]], i)
        else :
            dp[0][counter[idx]] = i

    for i in range(len(input_timer)-1):
        for j in range(106):
            if dp[i][j] >= 0 :
                for k in range(0, 10):
                    c_k = k % 10
                    c_k_v = counter[c_k]
                    val = dp[i][j] + ( pow(10, i+1) * k )
                    if val < 0 :
                        continue
                    if dp[i+1][c_k_v + j] == -1:
                        dp[i+1][c_k_v + j] = val
                    else :
                        dp[i+1][c_k_v + j] = min(dp[i+1][c_k_v + j], val)

    answer = pow(10, len(input_timer))
    for i in range(len(input_timer)):
        c_number = input_timer[::-1][:i+1]
        i_number = sum([ val * pow(10,idx) for idx, val in enumerate(c_number)])
        c_sum = sum([counter[j] for j in c_number])
        if i_number < dp[i][c_sum] :
            answer = min(answer, dp[i][c_sum]-i_number)
        else :
            if i == 0:
                if i + 1 == len(input_timer):
                    for j in range(1,11):
                        if counter[(i_number+j)%10] == counter[i_number]:
                            answer = min(answer, j)
                else :
                    for j in range(10):
                        if counter[i_number] == counter[j] :
                            if i_number < j :
                                answer = min(answer, j - i_number)
            else :
                for j in range(10):
                    n_idx = ( c_number[i] + j ) % 10
                    c_idx = n_idx % 10
                    if i + 1 == len(input_timer) :
                        n_idx = c_number[i] + j
                    if c_sum - counter[c_idx] < 0 or dp[i-1][c_sum-counter[c_idx]] < 0:
                        continue
                    rotate = (n_idx) * pow(10, i) + dp[i-1][c_sum-counter[c_idx]]
                    if i_number < rotate :
                        answer = min(answer, rotate-i_number)
    # print(answer)
    return answer
    
if __name__ == "__main__":
    print(main(input()))
    
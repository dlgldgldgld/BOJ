from math import ceil

def solution(alp, cop, problems):
    answer = 1e9
    dp = [[-1] * 301 for _ in range(301)]
    dp[alp][cop] = 0
    max_alp = 0
    max_cop = 0
    for i in problems :
        max_alp = max(max_alp, i[0])
        max_cop = max(max_cop, i[1])

    for i in range(alp, 151):
        for j in range(cop, 151):
            if dp[i][j] == -1 :
                continue
            for p in problems:
                limit_al, limit_co, rew_al, rew_co, cost = p
                if i >= limit_al and j >= limit_co :
                    next_i = i + rew_al
                    next_j = j + rew_co
                    if dp[next_i][next_j] == -1 :
                        dp[next_i][next_j] = dp[i][j] + cost
                    else :
                        dp[next_i][next_j] = min(dp[next_i][next_j], dp[i][j] + cost)
                else :
                    diff_al = limit_al - i
                    diff_co = limit_co - j
                    if diff_al < 0:
                        diff_al = 0
                    if diff_co < 0:
                        diff_co = 0
                    next_i = i + diff_al
                    next_j = j + diff_co
                    if dp[next_i][next_j] == -1 :
                        dp[next_i][next_j] = dp[i][j] + diff_al + diff_co
                    else :
                        dp[next_i][next_j] = min(dp[next_i][next_j], dp[i][j] + diff_al + diff_co)
    
    for i in range(alp, 151):
        for j in range(cop, 151):
            if i >= max_alp and j >= max_cop and dp[i][j] != -1:
                answer = min(answer, dp[i][j])
    
    print(answer)
    return answer
                    
solution(10,10,[[10,15,2,1,2],[20,20,3,3,4]])
solution(0, 0, [[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]])
    
    
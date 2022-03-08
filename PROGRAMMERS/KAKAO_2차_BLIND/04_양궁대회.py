def solution(n, info):
    answer = [0] * 11 
    # [0,0,0,0,0,0,0,0,0,0] , 0
    # [1,0,0,0,0,0,0,0,0,0] , 1
    # [0,1,0,0,0,0,0,0,0,0] , 2
    # [1,1,0,0,0,0,0,0,0,0] , 3
    # [0,0,1,0,0,0,0,0,0,0]
    lion_board = [0] * 11
    max_lion_board = [0] * 11
    max = 0
    noanswer = True
    for i in range (0, 2048) :
        k = list(str(bin(i & 2047)))[2:]
        k.reverse()
        for j, v in enumerate(k):
            lion_board[j] = int(v)

        lion_cnt = 0
        lion_score = 0
        app_score = 0
        for score in range(0, 11):
            if lion_board[score] == 1 :
                lion_cnt += info[score] + 1
                lion_score += (10-score)
            
            if lion_board[score] == 0 and info[score] > 0:
                app_score += (10-score)

        if ( lion_cnt <= n 
             and max <= (lion_score-app_score)
             and (lion_score-app_score) > 0 ):
            max = (lion_score-app_score)
            max_lion_board = lion_board[:]
            noanswer = False
            #print(lion_cnt, lion_score-app_score, i, lion_board)

    remain_arrow = n
    for i in range(0, 10):
        if max_lion_board[i] == True :
            answer[i] = info[i]+1
            remain_arrow -= answer[i]
    
    if remain_arrow > 0:
        answer[10] = remain_arrow
    
    if noanswer == True :
        answer = [-1]
    
    return answer

# info = [2,1,1,1,0,0,0,0,0,0,0]
# n = 5
# print(solution(n, info))

# info = [1,0,0,0,0,0,0,0,0,0,0]
# n = 1
# print(solution(n, info))

# info = [0,0,1,2,0,1,1,1,1,1,1]
# n = 9
# print(solution(n, info))

# info = [0,0,0,0,0,0,0,0,3,4,3]
# n = 10
# print(solution(n, info))
from itertools import combinations_with_replacement

def compare(a, b):
    return a[::-1] > b[::-1]


def solution(n, info):
    ret = [-1] * 12
    max_score = -1
    for comb in combinations_with_replacement(range(11), n):
        lion_arrow = [0] * 11
        for i in comb:
            lion_arrow[i] += 1
        score = 0
        for i in range(11):
            if info[i] < lion_arrow[i]:
                score += (10-i)
            elif info[i] >= lion_arrow[i] and info[i] != 0:
                score -= (10-i)
        
        if score <= 0 : 
            continue

        if max_score < score :
            max_score = score
            ret = lion_arrow[:]
        
        elif max_score == score:
            if compare(lion_arrow, ret) :
                ret = lion_arrow[:]
    
    if ret[0] == -1:
        ret = [-1]

    return ret


info = [0,0,1,2,0,1,1,1,1,1,1]
n = 9
print(solution(n, info))

# info = [0,0,0,0,0,0,0,0,3,4,3]
# n = 10
# print(solution(n, info))
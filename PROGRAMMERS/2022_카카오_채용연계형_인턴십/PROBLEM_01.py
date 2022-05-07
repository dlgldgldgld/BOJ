def get_mbti(mbti):
    answer = []
    
    if mbti['R'] < mbti['T'] :
        answer.append('T')
    else :
        answer.append('R')

    if mbti['C'] < mbti['F'] :
        answer.append('F')
    else :
        answer.append('C')

    if mbti['J'] < mbti['M'] :
        answer.append('M')
    else :
        answer.append('J')

    if mbti['A'] < mbti['N'] :
        answer.append('N')
    else :
        answer.append('A')

    return "".join(answer)

def solution(survey, choices):
    answer = ''
    score = [0,3,2,1,0,1,2,3]
    mbti = {
        'A' : 0,
        'N' : 0,
        'C' : 0,
        'F' : 0,
        'M' : 0,
        'J' : 0,
        'R' : 0,
        'T' : 0
    }

    for idx, val in enumerate(survey):
        ch_score = choices[idx]
        if ch_score < 4:
            mbti[val[0]] += score[ch_score]
        else :
            mbti[val[1]] += score[ch_score]

    answer = get_mbti(mbti)
    print(answer)
    return answer

solution(["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5] )
solution(["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5] )
def checker(place):
    players = []
    for i in range(5):
        for j in range(5):
            if place[i][j] == "P":
                players.append((i,j))

    for a_idx, a in enumerate(players):
        for b_idx, b in enumerate(players):
            if a_idx == b_idx :
                continue
            dis = abs(a[0] - b[0]) + abs(a[1] - b[1])
            if dis > 2 :
                continue
            if a[0] == b[0] or a[1] == b[1] :
                n_i = int(( a[0] + b[0] ) / 2)
                n_j = int(( a[1] + b[1] ) / 2)
                if place[n_i][n_j] != 'X' :
                    return 0
            else :
                if place[a[0]][b[1]] != 'X' or \
                place[b[0]][a[1]] != 'X' :
                    return 0

    return 1 

def solution(places):
    answer = []
    
    for place in places:
        answer.append(checker(place))
    
    print(answer)
    return answer

solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]])
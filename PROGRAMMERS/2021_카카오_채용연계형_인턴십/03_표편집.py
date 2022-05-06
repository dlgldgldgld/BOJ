from collections import deque
from heapq import heappush, heappop, heapify

def solution(n, k, cmds):
    cursor = k
    left_cursor = [ -i for i in range(0, k) ]
    right_cursor = [ i for i in range(k+1, n)]
    heapify(left_cursor)
    heapify(right_cursor)
    dellist = deque()
    
    for cmd in cmds :
        if cmd[0] == "U" or cmd[0] == "D":
            c, d = cmd.split()[0], int(cmd.split()[1])
            if c == "U":
                for _ in range(d):
                    heappush(right_cursor, cursor)
                    cursor = -heappop(left_cursor)
            elif c =="D" :
                for _ in range(d):
                    heappush(left_cursor, -cursor)
                    cursor = heappop(right_cursor)
        else:
            if cmd[0] == "C":
                dellist.append(cursor)
                if right_cursor:
                    cursor = heappop(right_cursor)
                else :
                    cursor = -heappop(left_cursor)
            else :
                recover = dellist.pop()
                if recover < cursor :
                    heappush(left_cursor, -recover)
                else :
                    heappush(right_cursor, recover)

    answer = ['O' for _ in range(n)]
    for val in dellist:
        answer[val] = 'X'
    
    return "".join(answer)

print(solution(8, 0, ["D 7", "C", "U 6", "C", "Z", "Z", "C"]))
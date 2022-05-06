from collections import deque
from heapq import heappush, heappop

def solution(n, start, end, roads, traps):
    def is_trap(node):
        f_idx = 0
        if node in traps:
            f_idx = pow(2, traps.index(node))
        return f_idx
        
    answer = 100000001
    edge = [[-1]*(n+1) for _ in range(n+1)]
    visited = [[False]*1024 for _ in range(n+1)]
    for r in roads:
        st, ed, val = r
        if edge[st][ed] != -1 :
            edge[st][ed] = min(edge[st][ed], val)
        else :
            edge[st][ed] = val

    que = []
    que.append([0, start, 0])
    
    while que:
        s, c, t = heappop(que)
        visited[c][t] = True
        if c == end :
            answer = min(answer, s)
            break

        for i in range(1, n+1):
            st, ed = c, i
            trap_st = is_trap(st)
            trap_ed = is_trap(ed)
            reverse_one = False
            if t & trap_st:
                reverse_one = not reverse_one
            if t & trap_ed:
                reverse_one = not reverse_one
            
            next_edge = 0
            if not reverse_one :
                if edge[st][ed] == -1:
                    continue
                next_edge = edge[st][ed]
            else :
                if edge[ed][st] == -1:
                    continue
                next_edge = edge[ed][st]
            
            ed_idx = is_trap(ed)
            if ed_idx & t:
                n_t = t ^ ed_idx
            else :
                n_t = t | ed_idx

            if visited[ed][n_t] == False :
                
                heappush(que, [s + next_edge, ed, n_t])

    print(answer)
    return answer
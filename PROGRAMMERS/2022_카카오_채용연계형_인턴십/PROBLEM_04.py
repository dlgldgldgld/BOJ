from collections import deque
edge = [[] for _ in range(50001)]

def solution(n, paths, gates, summits):
    answer = []
    
    for path in paths:
        edge[path[0]].append([path[1], path[2]])
        edge[path[1]].append([path[0], path[2]])
    
    l, r = 0, 10000000
    while( l < r ):
        is_visited = [0] * 50001
        middle = (l+r) / 2    
        
        for i in gates:
            is_possible = False
            
            que = deque()
            que.append([0, 0, -1, i])
            
            while(que):
                task = que.popleft()
                intensity, sub = task[0], task[1]
                curr, where_from = task[2], task[3]

                if curr == where_from :
                    intensity, sub
                    is_possible = True
                    break
                
                for e in edge[i]:
                    next_pos = e[0]
                    hour = e[1]
                    if e[1] <= middle:
                        n_sub = 0
                        n_intensity = 0
                        if sub != 0 and next_pos in summits :
                            continue
                        if next_pos in gates and next_pos != where_from :
                            continue
                        if next_pos in summits:
                            n_sub = next_pos
                        
                        n_intensity = max(hour, intensity)
                        if is_visited[next_pos] < 2 :
                            is_visited[next_pos] += 1
                            que.append([n_intensity, n_sub, next_pos, where_from])
        
        if is_possible :
            l = middle + 1
        else :
            r = middle

    return answer

solution(6, [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]], [1,3], [5])
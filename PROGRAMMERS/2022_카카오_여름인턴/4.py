from heapq import heappush, heappop

def solution(n, paths, gates, summits):
    summits = set(summits)
    gates = set(gates)
    visited = dict()
    # 다익스트라
    # 낮은 경로를 선택하면서 산봉우리가 나오면 반환.
    # 우선순위는 낮은 번호의 산봉우리.
    link = [dict() for _ in range(50001)]
    for (st, dep, dis) in paths:
        link[st][dep] = dis
        link[dep][st] = dis
    
    intensity = 0
    ans_intensity = 0
    ans_dep = 1e9
    queue = []
    for gate in gates:
        for dep, dist in link[gate].items():
            if dep in gates :
                continue
            heappush(queue, [dist, dep])

    while queue :
        dist, dep = heappop(queue)
        visited[dep] = 1
        intensity = max(intensity, dist)
        if ans_intensity != 0 and ans_intensity < intensity:
            break
        
        if dep in summits:
            ans_dep = min(ans_dep, dep)
            ans_intensity = intensity
            if ans_dep == min(summits) :
                break
            continue
            
        for n_dep, n_dist in link[dep].items():
            if n_dep in gates : continue
            if n_dep in visited: continue
            heappush(queue, [n_dist, n_dep])
    
    return [ans_dep, ans_intensity]

print(solution(6, [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]], [1,3], [5]))
# [5,3]

print(solution(7, [[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]], [1], [2,3,4]))
# [3,4]

print(solution(7, [[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]], [3,7], [1,5]))
# [5,1]

print(solution(5, [[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]], [1,2], [5]))
# [5,6]

print(solution(4, [[1,4,2], [1,3,2], [2,4,2]], [1], [2,3]))
# [2,2]
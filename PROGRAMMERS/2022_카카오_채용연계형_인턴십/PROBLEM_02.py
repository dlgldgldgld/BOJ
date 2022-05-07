from collections import deque

def solution(queue1, queue2):
    answer = 0
    q1_sum = sum(queue1)
    q2_sum = sum(queue2)
    
    q1 = deque(queue1)
    q2 = deque(queue2)
    
    while q1_sum != q2_sum:
        if answer >= 1000000:
            answer = -1
            break

        if len(q1) == 0 or len(q2) == 0:
            answer = -1
            break
        
        answer += 1
        if q1_sum > q2_sum :
            temp = q1.popleft()
            q2.append(temp)
            q1_sum -= temp
            q2_sum += temp
        elif q1_sum < q2_sum:
            temp = q2.popleft()
            q1.append(temp)
            q2_sum -= temp
            q1_sum += temp
    
    print(answer)
    return answer

solution([1,1], [1])
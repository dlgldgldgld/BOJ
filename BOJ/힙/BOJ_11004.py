from sys import stdin 
from heapq import heappush, heappop
input = stdin.readline
# input = open('input.txt', 'r').readline

n, k = map(int, input().split())
seq = list(map(int, input().split()))
max_heap = [-seq[0]]
for i in seq[1:]:
    if len(max_heap) < k :
        heappush(max_heap, -i)
    else :
        if -max_heap[0] > i :
            heappop(max_heap)
            heappush(max_heap, -i)
            
print(-max_heap[0])

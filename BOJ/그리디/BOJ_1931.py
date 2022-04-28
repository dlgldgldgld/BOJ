d = []
n = int(input())
for _ in range(n):
    begin, end = map(int, input().split())
    if end < begin:
        continue
    d.append([begin, end])

d.sort(key=lambda x: (x[1], x[0]))
max_time = 0
answer = 0
for i in d:
    begin, end = i
    if max_time <= begin:
        max_time = end
        answer += 1

print(answer)

n, k = map(int, input().split())
up = 1
down = 1

for i in range(k):
    up *= n
    down *= (i+1)
    n -= 1

print(int(up/down))

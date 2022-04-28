n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

answer = 0
for coin in coins[::-1]:
    if k >= coin:
        answer += int(k / coin)
        k = k % coin

print(answer)

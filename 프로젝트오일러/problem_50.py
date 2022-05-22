from math import sqrt

is_prime = [True] * 1000001

for i in range(2, 10000):
    for k in range(2, 500000):
        if i*k <= 1000000:
            is_prime[i*k] = False
        else :
            break

prime = []
for i in range(2, 1000001):
    if is_prime[i] == True:
        prime.append(i)

answer = 0
for i in range(len(prime)):
    for j in range(len(prime)):
        if i == j :
            continue
        temp = sum(prime[i:j])
        if temp > 1000000 :
            continue
        if answer > (j-i+1):
            continue
        if temp in prime :
            answer = max(answer, (j-i+1))
            print(temp, answer)

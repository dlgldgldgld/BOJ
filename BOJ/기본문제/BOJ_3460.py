# input = open('input.txt','r').readline
t = int(input())

def to_2th(n):
    ans = ""
    while n > 0:
        ans += str(n % 2)
        n //= 2
    return ans

for _ in range(t):
    a = int(input())
    n = to_2th(a)
    for idx, word in enumerate(n):
        if word == '1':
            print(idx, end=" ")
    
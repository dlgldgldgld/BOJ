from sys import stdin

input = stdin.readline
# input = open('input.txt').readline

t = int(input())
for i in range(t):
    tri = list(map(int, input().split()))
    tri.sort()
    if tri[2] >= tri[0] + tri[1]:
        print(f'Case #{i+1}: invalid!')
    else :
        if tri[0] == tri[1] and tri[1] == tri[2]:
            print(f'Case #{i+1}: equilateral')
        elif tri[0] == tri[1] or tri[1] == tri[2]:
            print(f'Case #{i+1}: isosceles')
        else :
            print(f'Case #{i+1}: scalene')

# input = open('input.txt', 'r').readline
a, b, n = map(int, input().split())
if a >= b :
    a = a % b

while n >= 0:
    n -= 1
    mok = a // b 
    a = a % b
    if a == 0 :
        break
    if a < b :
        a *= 10

print(mok)
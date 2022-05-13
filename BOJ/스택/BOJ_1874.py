from sys import stdin
input = stdin.readline
n = int(input())
top = 0
curr = []
answer = []
no_answer = False
for _ in range(n):
    a = int(input())
    if top < a :
        base = top
        for j in range(1, (a-top)+1):
            answer.append('+')
            curr.append(top + j)
        top = a
        answer.append('-')
        curr.pop()
    elif curr[-1] == a :
        answer.append('-')
        curr.pop()
    elif curr[-1] > a :
        no_answer = True

if no_answer :
    print('NO')
else :
    print("\n".join(answer))

    
    

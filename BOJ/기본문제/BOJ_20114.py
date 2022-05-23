from sys import stdin
input = stdin.readline
# input = open('input.txt','r').readline

n, h, w = map(int, input().split())
words = []
for i in range(h):
    words.append(input())

ans = ""
for i in range(n):
    sx, sy = i*w, 0
    is_find = False
    for j in range(h):
        for k in range(w):
            cx = sx + k
            cy = sy + j
            if words[cy][cx] != '?':
                ans += words[cy][cx]
                is_find = True
                break
        if is_find :
            break
    
    if is_find == False:
        ans += '?'

print(ans)
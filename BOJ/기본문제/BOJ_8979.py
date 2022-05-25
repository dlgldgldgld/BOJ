from sys import stdin 
input = stdin.readline
# input = open('input.txt', 'r').readline

n, k = map(int, input().split())
db = []
for i in range(n):
    idx, g, s, b = map(int, input().split())
    db.append([idx, g, s, b])

db.sort(key=lambda x :( -x[1], -x[2], -x[3]))
for rank, i in enumerate(db):
    if i[0] == k:
        for j in range(rank-1, -1, -1):
            if i[1:4] == db[j][1:4] :
                rank -= 1
        print(rank + 1)
        break
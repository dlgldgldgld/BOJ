from sys import stdin

input = stdin.readline
# input = open('input.txt','r').readline

n = int(input())
db = []
for _ in range(n):
    db.append(list(map(int, input().split())))

db.sort(key=lambda x : (x[1], x[0]))
for i in range(n):
    print( db[i][0], db[i][1])
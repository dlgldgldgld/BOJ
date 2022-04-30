from collections import deque
from dis import dis

class task:
    def __init__(self, x, y, dis, is_crush):
        self.x = x
        self.y = y
        self.dis = dis
        self.is_crush = is_crush

    def __str__(self):
        return f'x={self.x}, y={self.y}, dis={self.dis}, is_crush={self.is_crush}'

board = []
discovered = []
d_x = [1, 0, -1, 0]
d_y = [0, 1, 0, -1]
n, m = (0, 0)

def read():
    global n, m
    n, m = map(int, input().split())
    for _ in range(n):
        board.append(list(map(int, input())))
        discovered.append(list([[False, False] for _ in range(m)]))

def read_file():
    global n, m
    r = open("testcase.txt" ,"r")
    n, m = map(int, r.readline().split())
    for _ in range(n):
        board.append(list(map(int, r.readline().strip())))
        discovered.append(list([[False, False] for _ in range(m)]))

read()
# read_file()

que = deque()
discovered[0][0][0] = True
que.append([0,0,1,False])
answer = 10000001
call = 0

while que:
    c_x, c_y, c_dis, c_iscrash = que.popleft()
    call += 1
    if c_y == n-1 and c_x == m-1:
        answer = min(answer, c_dis)
        break

    for i in range(4):
        n_x = d_x[i] + c_x
        n_y = d_y[i] + c_y
        if n_x == -1 or n_y == -1 or n_x == m or n_y == n :
            continue
        if discovered[n_y][n_x][c_iscrash] == True:
            continue
        if board[n_y][n_x] == 1 and c_iscrash == False:
            discovered[n_y][n_x][1] = True
            que.append([n_x, n_y, c_dis + 1, True])
            continue
        
        if board[n_y][n_x] == 0:
            discovered[n_y][n_x][c_iscrash] = True
            que.append([n_x,n_y, c_dis + 1, c_iscrash])

# print(call)
if answer == 10000001:
    print(-1) 
else:
    print(answer)
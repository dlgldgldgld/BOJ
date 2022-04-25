from queue import Queue
from collections import deque
from sys import stdin

class st_task:
    def __init__(self, x, y, dis):
        self.x = x
        self.y = y
        self.dis = dis

    def __str__(self):
        return f'x={self.x}, y={self.y}, dis={self.dis}'

def main():
    # f = open("test.txt", "r")
    # w, h = map(int, input().split(' '))
    w, h = map(int, stdin.readline().split(' '))
    # w, h = map(int, f.readline().split(' '))
    board = []
    visited = []
    for _ in range(h) :
        # board.append(list(map(int, f.readline().split(' '))))
        board.append(list(map(int, stdin.readline().split(' '))))
        # board.append(list(map(int, input().split(' '))))
        visited.append([False] * w)

    d_x = [-1, 0, 1, 0]
    d_y = [0, 1, 0, -1]

    answer = -1
    call = 0

    queue = deque()
    for y in range(h):
            for x in range(w):
                if board[y][x] == 1 :
                    visited[y][x] == True
                    queue.append(st_task(x,y,0))

    while queue:
        task = queue.popleft()
        c_x = task.x
        c_y = task.y
        c_dis = task.dis
        # print(task)
        answer = max(answer, c_dis)
        call += 1
        for i in range(4):
            n_x = c_x + d_x[i]
            n_y = c_y + d_y[i]
            if n_x == -1 or n_y == -1 or n_x == w or n_y == h:
                continue
            if visited[n_y][n_x] == True or board[n_y][n_x] != 0:
                continue
            
            visited[n_y][n_x] = True
            queue.append(st_task(n_x,n_y,c_dis + 1))

    for x in range(w):
        for y in range(h):
            if board[y][x] == 0 and visited[y][x] == False:
                answer = -1

    print(answer)
    # print(call)

if __name__ == "__main__":
    main()
    # from cProfile import Profile
    # from pstats import Stats

    # profiler = Profile()
    # profiler.runcall(main)

    # stats = Stats(profiler)
    # stats.strip_dirs()
    # stats.sort_stats('cumulative')
    # stats.print_stats()
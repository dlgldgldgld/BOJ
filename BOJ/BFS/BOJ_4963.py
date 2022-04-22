from tkinter import N

in_map = [[0] * 50 for _ in range(50)]
visited = [[0] * 50 for _ in range(50)]

X_DIR = [-1, -1, 0, 1, 1, 1, 0, -1]
Y_DIR = [0, 1, 1, 1, 0, -1, -1, -1]

w, h = 0, 0


def tracking(x, y):
    if x == -1 or y == -1 or x == w or y == h:
        return

    if visited[x][y] == True:
        return

    for i in range(8):
        tracking(x + X_DIR[i], y + Y_DIR[i])


while True:
    w, h = map(int, input().split(" "))
    if w == 0 and h == 0:
        exit(0)

    for i in range(w):
        for j in range(h):
            in_map[i][j] = input()

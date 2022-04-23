import sys

sys.setrecursionlimit(10**6)

in_map = [[0] * 50 for _ in range(50)]
visited = []

X_DIR = [-1, -1, 0, 1, 1, 1, 0, -1]
Y_DIR = [0, 1, 1, 1, 0, -1, -1, -1]

w, h = 0, 0


def tracking(x, y):
    if visited[x][y] == True:
        return False

    visited[x][y] = True

    for i in range(8):
        n_x = x + X_DIR[i]
        n_y = y + Y_DIR[i]

        if n_x == -1 or n_y == -1 or n_x == w or n_y == h:
            continue

        if visited[n_x][n_y] == True:
            continue

        if in_map[n_x][n_y] != 0:
            tracking(n_x, n_y)

    return True


while True:
    visited = [[0] * 50 for _ in range(50)]
    w, h = map(int, input().split(" "))
    if w == 0 and h == 0:
        break

    for i in range(h):
        a = map(int, input().split(" "))
        for j, val in enumerate(a):
            in_map[j][i] = val

    answer = 0
    for i in range(w):
        for j in range(h):
            if in_map[i][j] != 0 and True == tracking(i, j):
                answer += 1

    print(answer)

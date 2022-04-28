board = [
    ["A", "B", "C"],
    ["D", "E", "F"],
    ["G", "H", "I"],
    ["J", "K", "L"],
    ["M", "N", "O"],
    ["P", "Q", "R", "S"],
    ["T", "U", "V"],
    ["W", "X", "Y", "Z"],
]

ans = 0
inp = input()

for i in inp:
    for idx, val in enumerate(board):
        if i in val:
            ans += idx + 3
            break

print(ans)

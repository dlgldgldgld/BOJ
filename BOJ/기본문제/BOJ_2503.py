from sys import stdin, stdout
input = stdin.readline
# input = open('input.txt', 'r').readline

n = int(input())
db = []
for _ in range(n):
    a,b,c = input().split()
    db.append([a, int(b), int(c)])

ans = 0
for i in range(111,1000):
    y_n = str(i)
    if y_n[0] == y_n[1] or y_n[1] == y_n[2] or y_n[0] == y_n[2]:
        continue
    if y_n[0] == '0' or y_n[1] == '0' or y_n[2] == '0':
        continue
    is_ans = True
    for m_n, m_s, m_b in db:
        y_s, y_b = 0, 0
        for k in range(3):
            if m_n[k] == y_n[k] :
                y_s += 1
            else :
                if y_n[k] in m_n:
                    y_b += 1
        if y_s != m_s or m_b != y_b :
            is_ans = False
            break
    if is_ans :
        ans += 1

print(ans)
        
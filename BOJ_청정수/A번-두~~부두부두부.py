n, m, k = map(int, input().split())
move = ( k - 3 )
if move < 0:
    for _ in range(abs(move)):
        m -= 1
        if m == 0 :
            m = n
    print(m)
else:
    for _ in range(move):
        m += 1
        if m == n+1:
            m = 1
    print(m)
    
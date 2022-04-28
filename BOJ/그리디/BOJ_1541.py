expr1 = input().split("-")
copy_expr1 = expr1[:]
for idx, expr in enumerate(expr1):
    expr2 = expr.split("+")
    if len(expr2) >= 2:
        a = sum(map(int, expr2))
        copy_expr1[idx] = a
answer = 0
for idx, a in enumerate(copy_expr1):
    if idx == 0:
        answer = int(a)
    else:
        answer -= int(a)
print(answer)

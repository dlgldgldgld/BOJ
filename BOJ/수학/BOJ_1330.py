a,b = map(int, input().split())
if a < b :
    print('<', end="")
elif a > b :
    print('>', end="")
else :
    print('==', end="")
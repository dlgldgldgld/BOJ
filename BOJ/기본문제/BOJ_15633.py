from itertools import permutations

n, m = map(int, input().split())
store = list(map(int, input().split()))
store.sort()
is_dup = dict()
for cm in permutations(store, m):
    is_dup.setdefault(cm, False)
    if is_dup[cm] == True:
        continue
    is_dup[cm] = True
    for k in cm:
        print(k, end=' ')
    print()
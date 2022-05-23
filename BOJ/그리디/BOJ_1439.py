# input = open('input.txt', 'r').readline

a = input()
ex_val = a[0]
cnt = [0, 0]
cnt[int(a[0])] += 1

for i in a[1:]:
    if ex_val != i:
        cnt[int(i)] += 1
    ex_val = i

print(min(cnt[0], cnt[1]))
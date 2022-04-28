LOWER_IDX = 97
ans = [-1] * 26
word = input()
for idx, val in enumerate(word):
    if ans[ord(val) - LOWER_IDX] == -1:
        ans[ord(val) - LOWER_IDX] = idx

for i in ans:
    print(i, end=" ")

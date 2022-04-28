patterns = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
words = input()
for pattern in patterns:
    while -1 != (f_idx := words.find(pattern)):
        words = words.replace(pattern, "1", 1)

print(len(words))

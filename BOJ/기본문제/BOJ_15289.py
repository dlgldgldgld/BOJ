r = 31
M = 1234567891

n = int(input())
key = input()
sum = 0 
for i in range(n):
    v = ord(key[i]) - 96
    sum += v * pow(r, i)

sum %= M
print(sum)
from sys import stdin

n = int(stdin.readline())
data = list(map(int, stdin.readline().rstrip().split(" ")))
data.sort()
print(data[0], data[-1])

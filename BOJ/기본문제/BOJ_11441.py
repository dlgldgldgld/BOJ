from sys import stdin, stdout

input = stdin.readline
# input = open("input.txt", "r").readline

n = int(input())
a = list(map(int, input().split()))
c_sum = [0] * (len(a) + 1)
for i in range(1, len(a) + 1):
    c_sum[i] = c_sum[i - 1] + a[i - 1]

m = int(input())
for _ in range(m):
    b, c = map(int, input().split())
    stdout.write(str(c_sum[c] - c_sum[b - 1]) + "\n")

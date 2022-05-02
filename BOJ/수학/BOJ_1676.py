n = int(input())
m = 1
for i in range(1, n+1):
    m *= i
k = list(str(m))
ans = 0
for j in k[::-1]:
    if j != '0' :
        print(ans)
        break
    ans += 1 

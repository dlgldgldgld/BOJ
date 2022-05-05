n = int(input())
a = list(map(int, input().split()))
a.sort()
l = 0
r = n - 1
max_val = 2000000000
answer = [-1,-1]
while(r > l):
    sum_val = abs(a[l] + a[r])
    if max_val > sum_val :
        max_val = sum_val
        answer[0] = a[l]
        answer[1] = a[r]

    l_val = abs(a[l] + a[r-1])
    r_val = abs(a[l+1] + a[r])

    if l_val < r_val :
        r -= 1
    elif l_val > r_val :
        l += 1
    else :
        l += 1
        r -= 1
    
print(answer[0], answer[1])
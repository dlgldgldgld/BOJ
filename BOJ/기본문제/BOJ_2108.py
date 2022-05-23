from sys import stdin
input = stdin.readline
# input = open('input.txt','r').readline

n = int(input())
BASE_VAL = 4000
store = [0]*8001

for _ in range(n):
    val = int(input())
    store[val + BASE_VAL] += 1

median_sum, median_cnt = 0, 0
middle_val, middle_idx = 0, (n//2) + 1
f_val, f_cnt, f_is_second = 0, 0, False
min_val, max_val = 4001, -4001
for idx, val in enumerate(store):
    c_number = (idx - BASE_VAL)
    if val > 0 :
        min_val = min(min_val, c_number)
        max_val = max(max_val, c_number)
        middle_idx -= val
        median_sum += (c_number * val)
        median_cnt += val
        if f_cnt < val:
            f_cnt = val
            f_val = c_number
            f_is_second = False
        elif f_cnt == val:
            if not f_is_second :
                f_val = c_number
            f_is_second = True

    if middle_idx <= 0:
        middle_val = c_number
        middle_idx = 10**6
    
print(round(median_sum / median_cnt))
print(middle_val)
print(f_val)
print(max_val - min_val)
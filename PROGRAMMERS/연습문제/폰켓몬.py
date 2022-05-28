def solution(nums):
    db = [0] * 200001  # db[n] = n번을 가지고 있니?
    for i in nums:
        db[i] = 1

    ans = 0
    for i in range(1, 200001):
        if db[i] == 1:
            ans += 1

    if ans > len(nums) / 2:
        ans = len(nums) / 2

    return ans

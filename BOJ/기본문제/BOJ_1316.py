def solution(word: str) -> bool:
    checker = [-1] * 26
    for idx, val in enumerate(word):
        a_idx = ord(val) - 97
        if checker[a_idx] == -1:
            checker[a_idx] = idx
        else:
            diff = idx - checker[a_idx]
            if diff == 1:
                checker[a_idx] = idx
            else:
                return False
    return True


n = int(input())
answer = 0
for _ in range(n):
    word = input()
    if solution(word):
        answer += 1
print(answer)

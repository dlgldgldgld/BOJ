def solution(gems):
    gem_cnt = len(set(gems))
    gem_dict = dict()
    l, r = 0, 0
    gem_dict.setdefault(gems[r], 1)
    gem_cnt -= 1
    answer = [0, 1e9]
    while True:
        if gem_cnt == 0:
            if (answer[1] - answer[0]) > (r - l):
                answer = [l + 1, r + 1]
        if gem_cnt > 0:
            if r == len(gems) - 1:
                break
            r += 1
            val = gem_dict.setdefault(gems[r], 0)
            if val == 0:
                gem_cnt -= 1
            gem_dict[gems[r]] += 1
        elif gem_cnt == 0:
            gem_dict[gems[l]] -= 1
            if gem_dict[gems[l]] == 0:
                gem_cnt += 1
            l += 1
    print(answer)
    return answer


solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"])
solution(["AA", "AB", "AC", "AA", "AC"])
solution(["XYZ", "XYZ", "XYZ"])
solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"])

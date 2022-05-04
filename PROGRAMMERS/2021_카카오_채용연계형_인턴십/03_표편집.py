from bisect import bisect_left, insort
from collections import deque

def solution(n, k, cmds):
    cursor = k
    store = [i for i in range(n)]
    dellist = deque()
    
    for cmd in cmds :
        if cmd[0] == "U" or cmd[0] == "D":
            c, d = cmd.split()[0], int(cmd.split()[1])
            if c == "U":
                cursor -= d
            elif c =="D" :
                cursor += d
        else:
            if cmd[0] == "C":
                # 삭제 연산
                f_idx = bisect_left(store, store[cursor])
                dellist.append(store[f_idx])
                if f_idx == len(store) - 1:
                    cursor -= 1
                del store[f_idx]
                pass
            else :
                # 'Z' 복구 작업
                recover = dellist.pop()
                f_idx = bisect_left(store, recover)
                if cursor >= f_idx :
                    cursor += 1
                insort(store, recover)

    answer = ['X' for _ in range(n)]
    for val in store:
        answer[val] = 'O'
    
    return "".join(answer)

def main():
    solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"])

main()
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(int(1e6))

input = stdin.readline
# input = open('input.txt','r').readline
p = [-1] * 51

def find(n):
    if p[n] == -1:
        return n
        
    p[n] = find(p[n])
    return p[n]

def merge(a, b, is_merge = False):
    pa, pb = find(a), find(b)
    if pa == pb :
        return True
    if is_merge :
        if pa < pb:
            p[pb] = pa
        else :
            p[pa] = pb
    return False


def extract_edge(n, str_list) :
    res = []
    if n == 1:
        return [[str_list[0], str_list[0]]]
    else :
        for i in range(n-1):
            res.append([str_list[i], str_list[i+1]])
    return res

n, m = map(int, input().split())
knowing_mans = list(map(int, input().split()))
edges = extract_edge(knowing_mans[0], knowing_mans[1:])
for st, ed in edges:
    merge(st, ed, True)

query_lists = []
for _ in range(m):
    query = list(map(int, input().split()))
    query_lists.append(query[1:])
    edges = extract_edge(query[0], query[1:])
    for st, ed in edges:
        merge(st, ed, True)

answer = m
is_know = set()
for man in knowing_mans[1:]:
    is_know.add(find(man))

for qlist in query_lists:
    is_possible_lie = True
    for node in qlist:
        p_idx = find(node)
        if p_idx in is_know:
            is_possible_lie = False
            break
    if is_possible_lie == False:
        answer -= 1

print(answer)
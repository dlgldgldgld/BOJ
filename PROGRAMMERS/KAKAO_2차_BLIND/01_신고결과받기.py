def solution(id_list, report, k):
    answer = [ 0 for _ in id_list ]
    userlists = { user : 0 for user in id_list }

    for r in set(report) :
        userlists[str(r.split()[1])] += 1

    reported_user = [ user for user, vote in userlists.items() if vote >= k ]
    for r in set(report) :
        if r.split()[1] in reported_user :
            answer[id_list.index(r.split()[0])] += 1
            
    return answer
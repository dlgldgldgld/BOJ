from math import ceil

def solution(fees, records):
    car_info = dict()
    for record in records:
        c_time, c_number, c_inout = record.split()
        c_hour, c_minute = map(int,c_time.split(":"))
        if c_inout == "IN":
            if c_number in car_info.keys():
                car_info[c_number][0] = True
                car_info[c_number][1] = (c_hour, c_minute)
            else :
                car_info[c_number] = [True, [c_hour, c_minute], 0]
        elif c_inout == "OUT":
            car_info[c_number][0] = False
            in_hour, in_minute = car_info[c_number][1]
            if in_minute > c_minute:
                c_hour -= 1
                c_minute += 60
            diff_hour   = c_hour - in_hour
            diff_minute = c_minute - in_minute
            car_info[c_number][2] += diff_hour * 60 + diff_minute
    
    for rec in car_info.items() :
        if rec[1][0] == True:
            rec[1][0] = False
            c_hour, c_minute = 23, 59
            in_hour, in_minute = rec[1][1]
            if in_minute > c_minute:
                c_hour -= 1
                c_minute += 60
            diff_hour   = c_hour - in_hour
            diff_minute = c_minute - in_minute
            rec[1][2] += diff_hour * 60 + diff_minute
    
    answer = []
    for rec in sorted(car_info.items()):
        recipe = 0
        sum = rec[1][2]
        if sum <= fees[0] :
            sum = 0
            recipe = fees[1]
        if sum - fees[0] >= 0:
            sum -= fees[0]
            recipe += fees[1]
        if sum > 0 :
            recipe += int(ceil(sum / fees[2])) * fees[3]    
        answer.append(recipe)
    return answer
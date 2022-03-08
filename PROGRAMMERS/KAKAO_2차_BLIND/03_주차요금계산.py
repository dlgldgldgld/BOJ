import datetime
from dataclasses import dataclass
from math import ceil

@dataclass
class parkingstat():
    inout : bool = False # In = True, Out = False
    in_time = datetime.time(hour = 0, minute = 0)
    used_time = datetime.timedelta(0,0)

class parkinginfo():
    def __init__ (self, record):
        self.timerec = datetime.time(hour = int(record.split()[0].split(':')[0]), minute = int(record.split()[0].split(':')[1]))
        self.carnumber = record.split()[1]
        self.inout = record.split()[2]

    def __str__ (self):
        return f'{self.timerec=}, {self.carnumber=}, {self.inout=}'

class parkingmanager():
    def __init__(self):
        self.car_list = dict()

    def getstatus(self, fees):
        res = []
        sorted_carlist = sorted(self.car_list.items())
        for key, item in sorted_carlist:
            used_time = (item.used_time.seconds / 60)
            base_time, base_fee, unit_time, unit_fee = fees
            sum = 0
            if used_time >= base_time or used_time > 0:
                sum += base_fee
                used_time -= base_time
            
            if used_time > 0 :
                sum += ceil(used_time / unit_time) * unit_fee
            res.append(sum)

        return res

    def updateremain(self):
        for key, item in self.car_list.items():
            if item.inout == True :
                item.used_time += datetime.timedelta(hours = 23, minutes = 59) - datetime.timedelta(hours=item.in_time.hour, minutes=item.in_time.minute )

    def car_in(self, carnumber, rec_time):
        if ( data := self.car_list.get(carnumber) ) is None :
            self.car_list[carnumber] = data = parkingstat()
            data.inout = True
            data.in_time = rec_time
        else :
            data.inout = True
            data.in_time = rec_time

    def car_out(self, carnumber, rec_time):
        if ( data := self.car_list.get(carnumber) ) is None :
            raise TypeError('의도치 않은 동작입니다.')
        else :
            data.inout = False
            t1 = datetime.timedelta(hours = rec_time.hour, minutes = rec_time.minute)
            t2 = datetime.timedelta(hours = data.in_time.hour, minutes = data.in_time.minute)
            data.used_time += ( t1 - t2)
            data.in_time = datetime.time(hour = 0,minute = 0)
 
    def join_car(self, record : parkinginfo):
        if record.inout == "IN" :
            self.car_in(record.carnumber, record.timerec)
        if record.inout == "OUT" :
            self.car_out(record.carnumber, record.timerec)
        pass

def solution(fees, records):
    park_manager = parkingmanager()
    for record in records :
        rec = parkinginfo(record)
        park_manager.join_car(rec)

    park_manager.updateremain()
    answer = park_manager.getstatus(fees)
    return answer
    
# fees = [180, 5000, 10, 600]
# records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
# print(solution(fees, records))

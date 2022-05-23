from sys import stdin

input = stdin.readline
# input = open('input.txt','r').readline

while True:
    year = int(input())
    if year == 0 :
        break

    if year < 1896 :
        print(year, 'No summer games')
    elif ( year - 1896 ) % 4 != 0:
        print(year, 'No summer games')
    else :
        if 1914 <= year and year <= 1918 :
            print(year, 'Games cancelled')
        elif 1939 <= year and year <= 1945 :
            print(year, 'Games cancelled')
        elif year > 2020 :
            print(year, 'No city yet chosen')
        else :
            print(year, 'Summer Olympics')

    

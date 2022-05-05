from decimal import Decimal

x, y = map(int, input().split())
if x == y or 99 == int ( Decimal(y) / Decimal(x) * 100 ):
    print(-1)
else :
    base = int ( Decimal(y) / Decimal(x) * 100 )
    r = 1000000000
    l = 0
    ex_r = -1
    ex_l = -1
    while True :
        middle = int((Decimal(r)+Decimal(l))/2)
        nodap = int(Decimal(y+middle) / Decimal(x+middle) * 100 )
        
        if base < nodap :
            r = middle
        else :
            l = middle
        if ( r == ex_r and l == ex_l ):
            break
        ex_r = r
        ex_l = l
    
    if base != int(Decimal(y+l)/Decimal(x+l)*100):
        print(l)
    elif base != int(Decimal(y+r)/Decimal(x+r)*100) :
        print(r)
    else :
        print(-1)
    
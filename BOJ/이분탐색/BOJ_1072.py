x, y = map(int, input().split())
if x == y or 99 == int ( y / x * 100 ):
    print(-1)
else :
    base = int ( y / x * 100 )
    r = 4000000000
    l = 0
    ex_r = -1
    ex_l = -1
    while True :
        middle = int((r+l)/2)
        nodap = int(( y + middle ) / ( x + middle ) * 100 )
        
        if base < nodap :
            r = middle
        else :
            l = middle
        if ( r == ex_r and l == ex_l ):
            break
        ex_r = r
        ex_l = l
    
    if base != int((y+l)/(x+l)*100):
        print(l)
    else :
        print(r)
    
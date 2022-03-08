import re
import math

def decitoN( n : int, k : int ) -> str :
    res = list()
    while n // k != 0 :
        m = n // k
        d = n % k 
        res.append(str(d))
        n = m
    res.append(str(n))
    res.reverse()
    return "".join(res)

def get_pattern( n : str )  :
    res = []
    p1 = re.compile('[1-9]+')
    for i in p1.findall(n) :
        res.append(int(i))
    return res

def is_prime_num(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False
    return True

def is_primecnt( n ) -> int :
    res = 0
    for num in n :
        if is_prime_num(num) and num > 1 :
            res += 1
    return res

def solution(n, k):
    answer = -1
    a = get_pattern(decitoN(n,k))
    answer = is_primecnt(a)
    return answer

counter = [6,2,5,5,4,5,6,3,7,5]

def verified(in_number, r):
    sum_in = sum([counter[int(i)] for i in in_number])
    for i in range(1, r+1):
        a = list(in_number)
        b = list(str(int(in_number) + i))
        for idx, val in enumerate(b[::-1]):
            if len(a)-(idx+1) >= 0 :
                a[len(a)-(idx+1)] = val

        str1 = ''.join(a)
        sum_out = sum([counter[int(i)] for i in str1])
        if sum_in == sum_out :
            break
    if i != r :
        print("Find respected answer at", str1 + ", answer is", i, "but your answer is", r)
        return False
    
    return True

if __name__ == "__main__":
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    aa = "0088"
                    res = main(aa)
                    print(f'main("{aa}")={res}')
                    assert verified(aa,res) == True
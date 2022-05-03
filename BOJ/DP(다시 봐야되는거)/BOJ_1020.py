counter = [6,2,5,5,4,5,6,3,7,5]

def main(i_number : str):
    dp = [[[-1]*106 for _ in range(10)] for _ in range(16)]
    dp2 = [[[-1]*106 for _ in range(10)] for _ in range(16)]
            
    # DP[N][K][S] = N자리를 K번 움직여서 S를 만들수 있는 최소 움직여야하는 수
                                    
    #     +   +---+   +---+   +   +   +---+
    #     |       |       |   |   |   |
    #     +   +---+   +---+   +---+   +---+
    #     |   |           |       |       |
    #     +   +---+   +---+       +   +---+
    #    (2)   (5)     (5)     (4)     (5)
    # +---+   +---+   +---+   +---+   +---+
    # |           |   |   |   |   |   |   |
    # +---+       +   +---+   +---+   +   +
    # |   |       |   |   |       |   |   |
    # +---+       +   +---+       +   +---+
    #   (6)     (3)     (7)     (5)    (6)

    # abc = input()
    abc = i_number
    input_timer = list(map(int, abc))[::-1]
    input_number = int(abc)
    all_sum = sum([counter[i] for i in input_timer])

    for i in range(10):
        idx = (input_timer[0] + i) % 10
        if dp[0][i][counter[idx]] > 0:
            dp[0][i][counter[idx]] = min(dp[0][counter[idx]], i)
        else :
            dp[0][i][counter[idx]] = i

        if dp2[0][i][counter[idx]] > 0:
            dp2[0][i][counter[idx]] = min(dp2[0][counter[idx]], i)
        else :
            dp2[0][i][counter[idx]] = i

    for i in range(len(input_timer)-1):
        for j in range(106):
            for k in range(10):
                if dp[i][k][j] >= 0 :
                    b_minus = False
                    if ( input_number % pow(10, i + 1) ) + dp[i][k][j] >= pow(10, i + 1):
                        b_minus = True
                    for l in range(0, 10):
                        c_l = ( input_timer[i+1] + l ) % 10
                        c_l_v = counter[c_l]
                        val = dp[i][k][j] + ( pow(10, i+1) * l )
                        if b_minus :
                            val -= pow(10, i+1)
                        if val <= 0 :
                            continue
                        if dp[i+1][l][c_l_v + j] == -1:
                            dp[i+1][l][c_l_v + j] = val
                        else :
                            dp[i+1][l][c_l_v + j] = min(dp[i+1][l][c_l_v + j], val)

    for i in range(len(input_timer)-1):
        for j in range(106):
            for k in range(10):
                if dp2[i][k][j] >= 0 :
                    b_minus = False
                    if ( input_number % pow(10, i + 1) ) + dp2[i][k][j] >= pow(10, i + 1):
                        b_minus = True
                    for l in range(0, 10):
                        c_l = ( input_timer[i+1] + l ) % 10
                        c_l_v = counter[c_l]
                        val = dp2[i][k][j] + ( pow(10, i+1) * l )
                        if b_minus :
                            val -= pow(10, i+1)
                        if val < 0 :
                            continue
                        if dp2[i+1][l][c_l_v + j] == -1:
                            dp2[i+1][l][c_l_v + j] = val
                        else :
                            dp2[i+1][l][c_l_v + j] = min(dp2[i+1][l][c_l_v + j], val)

    ll = len(input_timer)-1
    answer = 100000001
    for i in range(10):
        if dp[ll][i][all_sum] > 0 :
            answer = min(answer, dp[ll][i][all_sum])

        if dp2[ll][i][all_sum] > 0 :
            answer = min(answer, dp2[ll][i][all_sum])

    if answer == 100000001:
        answer = pow(10,ll+1)
        # print(pow(10,ll+1))
    else:
        # print(answer)
        pass

    return answer


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
        print(str1, i, "th")
        return False
    
    return True

if __name__ == "__main__":
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    aa = str(i) + str(j) + str(k) + str(l)
                    res = main(aa)
                    print(f'main("{aa}")={res}')
                    assert verified(aa,res) == True
            
            
            

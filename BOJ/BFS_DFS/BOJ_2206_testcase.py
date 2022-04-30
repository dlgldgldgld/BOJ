import random

with open("testcase.txt", "w") as w:
    w.write("1000 1000\n")
    for i in range(1000):
        for j in range(1000):
            w.write("0")
                

            ## 띄웜 띄웜
            # if ( i == 0 and j == 0 )or (i == 999 and j == 999) :
            #     w.write("0")
            # elif i % 2 == 0 and j == 0 :
            #     w.write("1")
            # elif i % 2 == 1 and j == 999:
            #     w.write("1")
            # else:
            #     #w.write(random.choice(["0", "1"]))
            #     w.write("0")
        w.write("\n")
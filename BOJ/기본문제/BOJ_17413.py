sentence = input()
is_tag = False
word = ""
for c in sentence :
    if c == '<':
        if len(word) > 0:
            print(word[::-1], end='')
            word = ""
        print(c, end='')
        is_tag = True
        continue
    elif c == '>':
        print(c, end='')
        is_tag = False
        continue

    if is_tag :
        print(c, end='')
    elif c == ' ':
        print(word[::-1], end=' ')
        word = ""
    else :
        word += c

if len(word) > 0:
    print(word[::-1])
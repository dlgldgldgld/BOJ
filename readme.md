# Tips of python
## list-element index 호출
- list.index(element)
ex) list = ['a','b','c']
    list.index('a') ==> 0 호출


# Tips
## 소수 구하기
- 소수를 구할때는 2부터 sqrt(N) 까지만 순환해도 찾을 수 있다.
  - 2 * 4 를 체크하는 것과 4 * 2를 체크하는 것은 동일하기 때문

## 시간 측정 ( python )
- cProfile, pstats module을 사용하면 함수의 속도를 측정할 수 있다.

```python
from cProfile import Profile
from pstats import Stats

profiler = Profile()
profiler.runcall(main)

stats = Stats(profiler)
stats.strip_dirs()
stats.sort_stats('cumulative')
stats.print_stats()
```

## 배열 입력 받기 ( python )
```python
board = []
for _ in range(n):
    # 12345
    board.append(list(map(int, input())))
    # 1 2 3 4 5
    board.append(list(map(int, input().split())))
```

## 입력 빠르게 받기 
```python
from sys import stdin
board = list(map(int,stdin.readline().split('')))
```

## 문자열 역순 출력
```python
board = ['a', 'b', 'c', 'd', 'e']
print(board[::-1])
```

## ascii
```python
ord('a')
chr(ord('a'))
```

## 순열, 조합
```python
# permutations : iterator 원소들로 길이 N인 순열을 생성. 두번째 인자를 전달하지 않으면 iterator 개수가 default 로 들어가는 듯
it = itertools.permutations([1,2,3,4], 2)
print(list(it))

it = itertools.permutations([1,2,3,4], 4)
print(list(it))

# combinations : 길이 N인 조합을 만들어준다.
it = itertools.combinations([1,2,3,4],2)
print(list(it))

# combinations_with_replacement : combination과 동일하지만 중복을 포함한다. 즉, 중복조합을 만들어준다.
it = itertools.combinations_with_replacement([1,2,3,4],2)
print(list(it))
```

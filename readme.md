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

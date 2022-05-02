#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
const unsigned long long MOD = 1000000007;

int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> Que;
		for (int i = 0; i < n; i++) {
			unsigned long long tmp;
			scanf("%lld", &tmp);
			Que.push(tmp);
		}
		unsigned long long ans = 1;
		while (1) {
			unsigned long long a = Que.top(); Que.pop();
			if (Que.size() == 0) break;
			unsigned long long b = Que.top(); Que.pop();
			unsigned long long tmp;
			tmp = (a*b) % MOD;
			ans = (ans*tmp) % MOD;
			if (Que.size() == 0) break;
			Que.push((a*b));
		}
		printf("%lld\n", ans);
	}
}
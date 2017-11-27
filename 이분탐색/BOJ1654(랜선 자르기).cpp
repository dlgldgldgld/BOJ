#include<cstdio>
#include<algorithm>
using namespace std;
long long inp[10000];
int main(void) {
	long long k, n;
	scanf("%lld %lld", &k, &n);
	for (int i = 0; i < k; i++) scanf("%lld", &inp[i]);
	long long lo = 0, hi = 1e12;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long count = 0;
		for (int i = 0; i < k; i++) {
			count += inp[i] / mid;
		}
		if (count < n) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	printf("%lld", lo);
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;

int inp[100000];
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &inp[i]);
	}

	int lo = 0, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cur = 0, count = m;
		for (int i = 0; i < n; i++) {
			if (inp[i] > mid) {
				count = -1; break;
			}
			else if (cur - inp[i] < 0) {
				cur = mid - inp[i];
				count--;
			}
			else {
				cur -= inp[i];
			}
		}
		if (count < 0) {
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	printf("%d", hi);
	return 0;
}
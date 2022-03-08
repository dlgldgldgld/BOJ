#include<cstdio>
#include<algorithm>
using namespace std;

int In[100000];
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &In[i]);

	int lo = 0, hi = 2e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int blue = m;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (In[i] > mid) {
				blue = -1;
				break;
			}
			sum += In[i];
			if (i == n - 1) {
				if (sum > mid) blue -= 2;
				else blue--;
			}
			else if (sum == mid) {
				blue--;
				sum = 0;
			}
			else if (sum > mid) {
				blue--;
				sum = In[i];
			}
		}
		if (blue < 0) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	printf("%d", hi);
	return 0;
}
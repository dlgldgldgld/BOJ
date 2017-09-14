#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> prime;
int p[1000001], In[101];
int n_p[101][78498], all_p[78498];
int main() {
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; j <= 1000000; j++) {
			if (i*j > 1000000) break;
			p[i*j] = 1;
		}
	}

	for (int i = 2; i <= 1000000; i++) if (p[i] == 0) prime.push_back(i);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		int k = 0;
		while (tmp > 1) {
			if (tmp % prime[k] != 0) { k++; }
			else {
				tmp /= prime[k];
				all_p[k]++;
				n_p[i][k]++;
			}

		}
	}
	int ldc = 1;
	for (int i = 0; i < 78498; i++) {
		all_p[i] /= n;
		if (all_p[i] > 0) ldc *= pow(prime[i], all_p[i]);
	}
	int ans;
	int t_i = 0, t_o = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 78498; j++) {
			int k = n_p[i][j] - all_p[j];
			if (k > 0) {
				t_i += k;
			}
			else {
				t_o += abs(k);
			}
		}
	}
	ans = min(t_i, t_o);
	printf("%d %d", ldc, ans);
}

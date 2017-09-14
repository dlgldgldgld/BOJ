#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int high[5001];
int dp[5001];
vector<int> vertex[5001];

int cal_dp(int n) {
	int &ret = dp[n];
	if (ret != -1) return ret;

	ret = 1;
	for (int next : vertex[n]) {
		ret = max(ret, cal_dp(next) + 1);
	}

	return ret;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &high[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (high[a] > high[b]) swap(a, b);
		vertex[a].push_back(b);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cal_dp(i);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", dp[i]);
	}
}

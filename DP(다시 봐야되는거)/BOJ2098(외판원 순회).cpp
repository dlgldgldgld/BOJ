#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 1e9;
int adj[16][16];
int dp[16][16][1 << 16];
int N;
int cal_dp(int a, int b, int sta) {
	if (sta == (1 << N) - 1) {
		return adj[b][0];
	}

	int &ret = dp[a][b][sta];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		if (adj[b][i] != 0) {
			if (!(sta & 1 << i)) {
				ret = min(ret, cal_dp(b, i, sta | (1 << i)) + adj[b][i]);
			}
		}
	}
	return ret;
}
int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = INF;
	for (int i = 0; i < N; i++) {
		if (adj[0][i] != 0) {
			ans = min(ans, cal_dp(0, i, (1 << 0 | 1 << i)) + adj[0][i]);
		}
	}
	printf("%d", ans);
	return 0;
}
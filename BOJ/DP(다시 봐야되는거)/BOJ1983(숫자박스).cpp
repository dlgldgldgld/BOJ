#include <cstdio>
#include <algorithm>
#define INF 999999999
#define INIT -1000000
using namespace std;

int dp[401][401][401], up[401], down[401], uc = 0, dc = 0, N;

int cal_dp(int n, int a, int b) {
	if (N - (n + 1) < max(uc - (a + 1), dc - (b + 1))) return INIT;
	if (a == uc || b == dc) return 0;

	int &ret = dp[n][a][b];
	if (ret != INF) return ret;

	ret = INIT;
	ret = max(ret, cal_dp(n + 1, a + 1, b + 1) + up[a] * down[b]);
	ret = max(ret, cal_dp(n + 1, a, b + 1));
	ret = max(ret, cal_dp(n + 1, a + 1, b));

	return ret;
}
int main(void) {
	int tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf(" %d", &tmp); if (tmp) up[uc++] = tmp; }
	for (int i = 0; i < N; i++) { scanf(" %d", &tmp); if (tmp) down[dc++] = tmp; }

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	printf("%d", cal_dp(0, 0, 0));
	return 0;
}
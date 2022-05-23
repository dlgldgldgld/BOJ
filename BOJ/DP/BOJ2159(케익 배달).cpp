#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x7ffffffffff
using namespace std;
long long dy[5] = { 1,0,-1,0 }, dx[5] = { 0,-1,0, 1 };
long long dp[100001][5], ex[2];
int N;
long long get_dis(long long sx, long long sy, long long dx, long long dy) {
	return abs(dx - sx) + abs(dy - sy);
}
int main(void) {
	scanf("%d", &N);
	scanf(" %lld %lld", &ex[0], &ex[1]);
	long long a, b;
	for (int i = 0; i < 5; i++) dp[0][i] = 0;
	for (int i = 1; i <= N; i++) {
		scanf(" %lld %lld", &a, &b);
		for (int k = 0; k < 5; k++) {
			dp[i][k] = INF;
			long long k_x = a + dx[k], k_y = b + dy[k];
			if (k_x <= 0 || k_x >= 100001) k_x = a;
			if (k_y <= 0 || k_y >= 100001) k_y = b;
			for (int j = 0; j < 5; j++) {
				long long j_x = ex[0] + dx[j], j_y = ex[1] + dy[j];
				if (i == 1) j_x = ex[0], j_y = ex[1];
				if (j_x <= 0 || j_x >= 100001) j_x = ex[0];
				if (j_y <= 0 || j_y >= 100001) j_y = ex[1];
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + get_dis(k_x, k_y, j_x, j_y));
			}
		}
		ex[0] = a; ex[1] = b;
	}
	long long ans = INF;
	for (int i = 0; i < 5; i++) {
		ans = min(ans, dp[N][i]);
	}
	printf("%lld", ans);
}
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD = 1000000003;
int dp[1001][1001][4];
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	dp[3][0][0] = 1;
	dp[3][1][1] = dp[3][1][2] = dp[3][1][0] = 1;
	dp[3][2][3] = 1;
	for (int i = 4; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][2]) % MOD;
			dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][3]) % MOD;
			if (j - 1 >= 0) {
				dp[i][j][2] = dp[i - 1][j - 1][0];
				dp[i][j][3] = dp[i - 1][j - 1][1];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += dp[n][k][i];
		ans %= MOD;
	}
	printf("%d", ans);
	return 0;
}
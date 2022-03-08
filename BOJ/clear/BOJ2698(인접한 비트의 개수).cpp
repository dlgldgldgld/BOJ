#include<cstdio>
int dp[101][100][2];
int main(void) {
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int N = 2; N <= 100; N++) {
		for (int K = 0; K < N; K++) {
			dp[N][K][1] = dp[N - 1][K][0];
			if (K - 1 >= 0) dp[N][K][1] += dp[N - 1][K - 1][1];
			dp[N][K][0] = dp[N - 1][K][0] + dp[N - 1][K][1];
		}
	}

	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b][0] + dp[a][b][1]);
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long dp[11][101][101][101], fact[11];
int n;

long long get_Combination(int n, int p, int c) {
	long long ret = fact[n];
	for (int i = 0; i < c; i++) {
		ret /= fact[p];
	}
	return ret;
}
long long cal_dp(int N, int R, int G, int B) {
	if (R < 0 || G < 0 || B < 0) return 0;
	if (N == n + 1) return 1;

	long long &ret = dp[N][R][G][B];
	if (ret != -1) return ret;

	ret = 0;
	ret += cal_dp(N + 1, R - N, G, B);
	ret += cal_dp(N + 1, R, G - N, B);
	ret += cal_dp(N + 1, R, G, B - N);

	if (N % 2 == 0) {
		int cnt = N / 2;
		ret += cal_dp(N + 1, R - cnt, G - cnt, B) * get_Combination(N, cnt, 2);
		ret += cal_dp(N + 1, R - cnt, G, B - cnt) * get_Combination(N, cnt, 2);
		ret += cal_dp(N + 1, R, G - cnt, B - cnt) * get_Combination(N, cnt, 2);
	}

	if (N % 3 == 0) {
		int cnt = N / 3;
		ret += cal_dp(N + 1, R - cnt, G - cnt, B - cnt) * get_Combination(N, cnt, 3);
	}

	return ret;
}
int main(void) {
	int r, g, b;
	scanf("%d %d %d %d", &n, &r, &g, &b);
	fact[0] = 1;
	for (int i = 1; i <= 10; i++) fact[i] = i * fact[i - 1];
	memset(dp, -1, sizeof(dp));
	printf("%lld", cal_dp(1, r, g, b));
}
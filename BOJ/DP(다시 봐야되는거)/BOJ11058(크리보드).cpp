#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;

long long dp[101];

long long cal_dp(int N) {
	long long &ret = dp[N];
	if (ret != -1) return ret;
	if (N == 0) return ret = 0;

	ret = cal_dp(N - 1) + 1;
	if (N > 2) {
		for (int i = 1; i <= N - 2; i++) {
			ret = max(ret, cal_dp(N - 2 - i) * (i + 1));
		}
	}
	return ret;
}
int main(void) {
	int n;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%lld", cal_dp(n));
}
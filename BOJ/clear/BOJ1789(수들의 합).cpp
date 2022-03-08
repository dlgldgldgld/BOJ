#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 1e9;
long long dp[1000001];
int main(void) {
	dp[1] = 0;
	dp[2] = 2;
	for (int i = 3; i <= 94000; i++) {
		dp[i] = i + dp[i - 1];
	}
	long long n;
	scanf("%lld", &n);
	for (int i = 0; i < 94000; i++) {
		if (dp[i] < n && dp[i + 1] >= n) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int dp[2001][2001];
// 182
int cal_dp(int s, int ex) {
	if (s == 0) return 1;
	if (s < 0) return 0;
	int &ret = dp[s][ex];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = ex+1; i <= s; i++) {
		if (s - i < 0) break;
		ret += cal_dp(s - i, i);
		ret %= 100999;
	}
	return ret;
}

int main(void) {
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < T; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", cal_dp(tmp, 0));
	}
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
#define INF 999999999
#define m_size 1503
using namespace std;

int dp[m_size][m_size][3], r,c, b_sum[m_size][m_size], a_sum[m_size][m_size];
pair<char,int> map[m_size][m_size];

int cal_dp(int R, int C, int dir) {
	if (R == r && C == c) { 
		return (dir==0) ? 0 : b_sum[R-1][C]; 
	}
	if (R > r || R <= 0 || C <= 0 || C > c) {
		return -INF;
	}

	int & ret = dp[R][C][dir];
	if (ret != -1) return ret;
	if (dir == 0) {
		ret = cal_dp(R + 1, C, 0);
		ret = max(ret, cal_dp(R, C + 1, 1) + a_sum[R + 1][C]);
		ret = max(ret, cal_dp(R + 1, C + 1, 2) + a_sum[R + 1][C]);
	}
	else if (dir == 1) {
		ret = cal_dp(R + 1, C, 0) + b_sum[R - 1][C];
		ret = max(ret, cal_dp(R, C + 1, 1) + a_sum[R + 1][C] + b_sum[R - 1][C]);
		ret = max(ret, cal_dp(R + 1, C + 1, 2) + a_sum[R + 1][C] + b_sum[R - 1][C]);
	}
	else {
		ret = cal_dp(R + 1, C, 0) + b_sum[R - 1][C];
		ret = max(ret, cal_dp(R, C + 1, 1) + a_sum[R + 1][C] + b_sum[R-1][C]);
		ret = max(ret, cal_dp(R + 1, C + 1, 2) + a_sum[R + 1][C] + b_sum[R - 1][C]);
	}
	return ret;
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int i = 1 ; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c%d", &map[i][j].first, &map[i][j].second);
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].first == 'B') {
				b_sum[i][j] += map[i][j].second;
			}
			b_sum[i][j] += b_sum[i - 1][j];
		}
	}

	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].first == 'A') {
				a_sum[i][j] += map[i][j].second;
			}
			a_sum[i][j] += a_sum[i + 1][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", cal_dp(1, 1, 0));
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#define INF 999999999
using namespace std;

int dp[1003][1003][2], n, m, p_sum[1003][1003];
pair<int, int> In[1001];

int cal_dp(int l, int r, int lr) {
	if (l == m && r == m) return 0;
	if (r<m || l>m) return INF;

	int &ret = dp[l][r][lr];
	if (ret != -1) return ret;

	ret = INF;
	if (lr == 0) {
		int tl = In[l + 1].first - In[l].first, tr = In[r].first - In[l].first;
		ret = min(cal_dp(l + 1, r, 0) + tl * (p_sum[1][l] + p_sum[r + 1][n]), cal_dp(l + 1, r, 1) + tr * (p_sum[1][l] + p_sum[r + 1][n]));
	}
	else {
		int tl = In[r].first - In[l].first, tr = In[r].first - In[r - 1].first;
		ret = min(cal_dp(l, r - 1, 0) + tl*(p_sum[r][n] + p_sum[1][l - 1]), cal_dp(l, r - 1, 1) + tr * (p_sum[r][n] + p_sum[1][l - 1]));
	}

	return ret;
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &In[i].first, &In[i].second);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			p_sum[i][j] += p_sum[i][j - 1] + In[j].second;
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = min(cal_dp(1, n, 0), cal_dp(1, n, 1));
	printf("%d", ans);
	return 0;
}
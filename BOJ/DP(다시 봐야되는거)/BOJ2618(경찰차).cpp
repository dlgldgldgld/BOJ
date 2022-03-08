#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#define INF 99999999
using namespace std;
int track[1001][1001];
int dp[1001][1001], N, k;
pair<int, int> In[1001];
inline int get_dis(int sx, int sy, int dx, int dy) {
	return abs(dx - sx) + abs(dy - sy);
}
int cal_dp(int a, int b) {
	if (a == k + 1 || b == k + 1) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = INF;
	int tmp = max(a, b);
	int dis = (a == 1) ? get_dis(1, 1, In[tmp].first, In[tmp].second) : get_dis(In[a - 1].first, In[a - 1].second, In[tmp].first, In[tmp].second);
	int tmp_2 = ret;
	ret = min(ret, cal_dp(tmp + 1, b) + dis);
	if (tmp_2 != ret) {
		track[a][b] = 1;
	}
	dis = (b == 1) ? get_dis(N, N, In[tmp].first, In[tmp].second) : get_dis(In[b - 1].first, In[b - 1].second, In[tmp].first, In[tmp].second);
	tmp_2 = ret;
	ret = min(ret, cal_dp(a, tmp + 1) + dis);
	if (tmp_2 != ret) {
		track[a][b] = 2;
	}
	return ret;
}

void print_ouf(int a, int b) {
	int t = track[a][b];
	printf("%d\n", t);
	if (a == k || b == k) return;
	int tmp = max(a, b);
	if (t == 1) {
		print_ouf(tmp + 1, b); return;
	}
	else {
		print_ouf(a, tmp + 1); return;
	}
}
int main(void) {
	scanf("%d", &N);
	scanf(" %d", &k);

	for (int i = 1; i <= k; i++) {
		scanf(" %d %d", &In[i].first, &In[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cal_dp(1, 1));
	print_ouf(1, 1);
}
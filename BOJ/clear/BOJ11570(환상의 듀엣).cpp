#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 999999999
using namespace std;

int dp[2001][2001], In[2001];
int n;

int cal_dp(int f, int s) {
	if (f == n || s == n) return 0;
	
	int &ret = dp[f][s];
	if (ret != -1) return ret;
	
	int t = max(f, s) + 1;
	
	ret = INF;
	ret = min(ret, cal_dp(f, t) + ((s == 0) ? 0 : abs(In[t] - In[s])));
	ret = min(ret, cal_dp(t, s) + ((f == 0) ? 0 : abs(In[t] - In[f])));

	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &In[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", cal_dp(0, 0));
}
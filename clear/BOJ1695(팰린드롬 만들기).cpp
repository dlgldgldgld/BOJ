#include<cstdio> 
#include<string> 
#include<cstring> 
#include<algorithm> 
using namespace std;

int In[5001];
int dp[5001][5001];
int p(int s, int e)
{
	if (s > e) return 0;
	int &ret = dp[s][e];
	if (ret != -1) { return ret; }
	ret = 0;
	if (In[s] == In[e])
		ret = p(s + 1, e - 1);
	else {
		ret = p(s + 1, e) + 1;
		ret = min(ret, p(s, e - 1) + 1);
	}
	return ret;
}
int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &In[i]);
	}
	memset(dp, -1, sizeof(dp));
	int ans = p(0, n - 1);
	printf("%d", ans);

	return 0;
}
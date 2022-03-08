#include<cstdio>
#include<algorithm>
using namespace std;
int dp[257][257], c[257][257], In[257];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &In[i]);
		c[i][i] = In[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			c[j][j+i] = min(c[j][j+i-1], c[j+1][j+i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n-i; j++) {
			if (i == 1) {
				dp[j][j+i] = abs(In[j] - In[j+i]);
				continue;
			}
			dp[j][j+i] = 99999999;
			for (int k = j; k < j+i; k++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j+i] + abs(c[j][k] - c[k+1][j+i]));
			}
		}
	}
	printf("%d", dp[1][n]);
}
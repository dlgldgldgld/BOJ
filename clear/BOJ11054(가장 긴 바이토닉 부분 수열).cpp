#include<cstdio> 
#include<string> 
#include<cstring> 
#include<algorithm> 
using namespace std;
int dp_g[1001], dp_l[1001];
int In[1001];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &In[i]);
	}
	fill(dp_g, dp_g + n, 1);
	fill(dp_l, dp_l + n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (In[i] > In[j]) {
				dp_g[i] = max(dp_g[i], dp_g[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (In[i] > In[j]) {
				dp_l[i] = max(dp_l[i], dp_l[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp_g[i] + dp_l[i] - 1);
	}
	printf("%d", ans);
}
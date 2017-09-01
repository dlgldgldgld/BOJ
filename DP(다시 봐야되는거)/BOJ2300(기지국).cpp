#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#define INF 20000000000
#define ms 10001
#define t_size 16384
using namespace std;
typedef pair<long long, long long> P;
P In[ms];
long long M[t_size * 2 + 1];
long long dp[ms];
int n;
void update(int idx, long long value) {
	idx += t_size;
	M[idx] = abs(value);
	while (idx > 1) {
		idx /= 2;
		M[idx] = max(M[idx * 2], M[idx * 2 + 1]);
	}
}
inline long long get_M(int L, int R, int Node_num, int T_L, int T_R) {
	if (L > T_R || R < T_L) return 0;
	if (L <= T_L && T_R <= R) return M[Node_num];
	int mid = (T_L + T_R) / 2;
	int ret = max(get_M(L, R, Node_num * 2, T_L, mid), get_M(L, R, Node_num * 2 + 1, mid + 1, T_R));
	return ret;
}

bool cmp(P a, P b) {
	return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &In[i].first, &In[i].second);
	}
	sort(In + 1, In + n + 1);

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		long long y = abs(In[i].second);
		for (int j = i; j >= 1; j--) {
			y = max(y, abs(In[j].second));
			long long l = max(abs(In[i].first - In[j].first), 2 * y);
			dp[i] = min(dp[i], dp[j - 1] + l);
		}
	}
	printf("%lld", dp[n]);
	return 0;
}
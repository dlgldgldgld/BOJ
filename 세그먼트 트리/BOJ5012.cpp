#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<set>
#define INF 100001
#define t_size 131072
using namespace std;
typedef long long ll;
typedef pair <ll, int > plli;
typedef pair<ll, ll > pll;
plli In[t_size];
ll pre[t_size * 2 + 1], cnt[t_size * 2 + 1];

bool cmp(plli a, plli b) {
	return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}

void update(int idx, int value, int mode) { // 1ÀÏ‹š pre, 0ÀÏ‹š cnt
	idx += t_size;
	if (mode == 1) pre[idx] = value;
	else cnt[idx] = value;

	while (idx > 1) {
		idx /= 2;
		if (mode == 1) pre[idx] = pre[2 * idx] + pre[2 * idx + 1];
		else cnt[idx] = cnt[2 * idx] + cnt[2 * idx + 1];
	}
}

ll sum_pre(int L, int R, int node, int T_L, int T_R) {
	if (L > T_R || R < T_L) return 0;
	if (L <= T_L && T_R <= R) return pre[node];

	int mid = (T_L + T_R) / 2;
	ll ret = sum_pre(L, R, node * 2, T_L, mid) + sum_pre(L, R, node * 2 + 1, mid + 1, T_R);
	return ret;
}

ll sum_cnt(int L, int R, int node, int T_L, int T_R) {
	if (L > T_R || R < T_L) return 0;
	if (L <= T_L && T_R <= R) return cnt[node];

	int mid = (T_L + T_R) / 2;
	ll ret = sum_cnt(L, R, node * 2, T_L, mid) + sum_cnt(L, R, node * 2 + 1, mid + 1, T_R);
	return ret;
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &In[i].first);
		In[i].second = i;
	}

	sort(In, In + n, cmp);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		update(In[i].second, 1, 1);
		ll tmp = sum_pre(In[i].second + 1, n, 1, 0, t_size - 1);
		update(In[i].second, tmp, 0);
		tmp = sum_cnt(In[i].second + 1, n, 1, 0, t_size - 1);
		ans += tmp;
	}

	printf("%lld", ans);
}
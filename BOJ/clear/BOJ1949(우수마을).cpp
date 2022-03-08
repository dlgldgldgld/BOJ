#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
int dp[10001][2], town[10001];
vector<int> vertex[10001];

int usoo(int Num, int visit, int prev) {
	if (vertex[Num].size() == 0) return 0;
	int &ret = dp[Num][visit];
	if (ret != -1) return ret;

	ret = 0;
	for (int next : vertex[Num]) {
		int tmp = 0;
		if (next != prev) {
			if (visit == 0) {
				tmp = max(tmp, usoo(next, 1, Num) + town[next]);
			}
			tmp = max(tmp, usoo(next, 0, Num));

			ret += tmp;
		}
	}

	return ret;
}
int main(void) {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) scanf("%d", &town[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}

	int ans = usoo(1, 0, -1);
	ans = max(ans, usoo(1, 1, -1) + town[1]);

	printf("%d", ans);
}
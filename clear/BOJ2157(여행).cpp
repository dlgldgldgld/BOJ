#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#define m_size 305
#define INF 99999999
using namespace std;

int DP[m_size][m_size], vertex[m_size][m_size];
int n, m, k, ck = 0;
int cal(int pos, int visit) {
	if (visit >= m) return -INF;
	if (pos == n) {
		ck = 1;	return 0;
	}
	int &ret = DP[pos][visit];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (vertex[pos][i] != 0) {
			ret = max(ret, vertex[pos][i] + cal(i, visit + 1));
		}
	}
	if (ret == 0) return -INF;
	return ret;
}
int main() {
	memset(DP, -1, sizeof(DP));

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a < b) {
			vertex[a][b] = max(vertex[a][b], c);
		}
	}

	int ans = cal(1, 0);
	if (ck == 1) {
		cout << ans;
	}

}
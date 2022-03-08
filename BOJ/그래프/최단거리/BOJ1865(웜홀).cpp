#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
vector<pii> vertex[501];
int dist[501];
const int INF = 1e9;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 1; i <= n; i++) vertex[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vertex[a].push_back(pii(b, c));
			vertex[b].push_back(pii(a, c));
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vertex[a].push_back(pii(b, -c));
		}
		bool m_cycle = false;
		fill(dist, dist + n + 1, INF);
		dist[1] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				for (pii k : vertex[j]) {
					int next = k.first, d = k.second;
					if (dist[j] != INF && dist[next] > dist[j] + d) {
						dist[next] = dist[j] + d;
						if (i == n - 1) { m_cycle = true; }
					}
				}
			}
		}
		if (m_cycle) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}
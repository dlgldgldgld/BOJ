#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
vector<int> adj[20001];
int Group[20001];
int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}


		int chk = 0;
		bool visit[20001];
		fill(visit, visit + 20001, false);
		fill(Group, Group + n + 1, -1);
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				queue<pii> Que;
				Que.push(pii(i, 0));
				while (Que.size() != 0) {
					int curr = Que.front().first;
					int side = Que.front().second;
					Group[curr] = side;
					Que.pop();
					if (visit[curr]) continue;
					visit[curr] = true;
					for (int next : adj[curr]) {
						if (visit[next] && Group[next] == side) {
							chk = 1;
						}
						if (!visit[next]) {
							Que.push(pii(next, (side + 1) % 2));
						}
					}
				}
			}
		}

		if (chk == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
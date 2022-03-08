#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<int> adj[1001];
bool visit[1001];

void dfs(int s) {
	if (visit[s]) return;
	visit[s] = true;
	printf("%d ", s);
	for (int next : adj[s]) {
		dfs(next);
	}
}
int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	fill(visit, visit + n + 1, false);
	dfs(v);
	printf("\n");
	fill(visit, visit + n + 1, false);
	queue<int> Que;
	Que.push(v);
	while (Que.size() != 0) {
		int curr = Que.front();
		Que.pop();
		if (visit[curr]) continue;
		printf("%d ", curr);
		visit[curr] = true;
		for (int next : adj[curr]) {
			Que.push(next);
		}
	}
	return 0;
}
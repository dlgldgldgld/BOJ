#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int visited[1001];
vector<int> adj[1001];

void bfs(int s) {
	queue<int> Que;
	Que.push(s);
	while (Que.size() != 0) {
		int curr = Que.front();
		Que.pop();
		if (visited[curr] == 1) continue;
		visited[curr] = 1;
		for (int next : adj[curr]) {
			Que.push(next);
		}
	}
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	fill(visited, visited + n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == -1) {
			bfs(i);
			ans++;
		}
	}
	printf("%d\n", ans);
}
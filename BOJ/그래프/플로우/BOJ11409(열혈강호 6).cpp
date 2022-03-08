#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// Customer Data Struct
const int MAX_V = 400;
const int ALL_V = MAX_V * 2 + 2;
const int S = ALL_V - 1, E = ALL_V - 2;
const int INF = 1e9;
int w[ALL_V][ALL_V], c[ALL_V][ALL_V], f[ALL_V][ALL_V];
vector<int> adj[ALL_V];
int main(void) {
	int n, m, result = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		adj[S].push_back(i); adj[i].push_back(S);
		c[S][i] = 1;
	}

	for (int i = 0; i < m; i++) {
		adj[E].push_back(i + MAX_V); adj[i + MAX_V].push_back(E);
		c[i + MAX_V][E] = 1;
	}

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a = a + MAX_V - 1;
			adj[i].push_back(a); adj[a].push_back(i);
			c[i][a] = 1;
			w[i][a] = b; w[a][i] = -b;
		}
	}
	int total = 0;
	while (1) {
		queue<int> Que;
		int prev[ALL_V], dist[ALL_V];
		bool InQue[ALL_V];

		fill(prev, prev + ALL_V, -1);
		fill(dist, dist + ALL_V, -INF);
		fill(InQue, InQue + ALL_V, false);
		Que.push(S);
		InQue[S] = true;
		dist[S] = 0;
		while (Que.size() != 0) {
			int curr = Que.front();
			Que.pop();
			InQue[curr] = false;

			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && dist[next] < dist[curr] + w[curr][next]) {
					dist[next] = dist[curr] + w[curr][next];
					prev[next] = curr;
					if (InQue[next] == false) {
						Que.push(next);
						InQue[next] = true;
					}
				}
			}
		}
		if (prev[E] == -1) break;
		int flow = INF;

		for (int i = E; i != S; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = E; i != S; i = prev[i]) {
			result += flow * w[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total++;
	}
	printf("%d\n%d", total, result);
	return 0;
}
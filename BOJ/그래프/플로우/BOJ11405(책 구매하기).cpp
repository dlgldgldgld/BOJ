#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// Customer Data Struct
const int MAX_V = 100;
const int ALL_V = MAX_V * 2 + 2;
const int S = ALL_V - 1, E = ALL_V - 2;
const int INF = 1e9;
int w[ALL_V][ALL_V], c[ALL_V][ALL_V], f[ALL_V][ALL_V];
vector<int> adj[ALL_V];
int main(void) {
	int n, m, result = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		adj[E].push_back(i); adj[i].push_back(E);
		c[i][E] = tmp;
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		adj[i + MAX_V].push_back(S); adj[S].push_back(i + MAX_V);
		c[S][i + MAX_V] = tmp;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; scanf("%d", &tmp);
			adj[i + MAX_V].push_back(j); adj[j].push_back(i + MAX_V);
			c[i + MAX_V][j] = INF;
			w[i + MAX_V][j] = tmp; w[j][i + MAX_V] = -tmp;
		}
	}

	while (1) {
		queue<int> Que;
		int prev[ALL_V], dist[ALL_V];
		bool InQue[ALL_V];

		fill(prev, prev + ALL_V, -1);
		fill(dist, dist + ALL_V, INF);
		fill(InQue, InQue + ALL_V, false);
		Que.push(S);
		InQue[S] = true;
		dist[S] = 0;

		while (Que.size() != 0) {
			int curr = Que.front();
			Que.pop();
			InQue[curr] = false;

			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + w[curr][next]) {
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
	}
	printf("%d", result);
	return 0;
}
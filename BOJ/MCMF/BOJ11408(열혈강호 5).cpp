#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX_V = 400;
const int INF = 1e9;
const int ALL_V = MAX_V * 2 + 2;
const int S = ALL_V - 1, E = ALL_V - 2;
int n, m, c[ALL_V][ALL_V], w[ALL_V][ALL_V], f[ALL_V][ALL_V];
vector<int> adj[ALL_V];
int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		adj[S].push_back(i); adj[i].push_back(S);
		c[S][i] = 1;
	}
	for (int i = MAX_V; i < MAX_V + m; i++) {
		adj[i].push_back(E); adj[E].push_back(i);
		c[i][E] = 1;
	}
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a = a - 1 + MAX_V;
			adj[i].push_back(a); adj[a].push_back(i);
			w[i][a] = b; w[a][i] = -b; c[i][a] = 1;
		}
	}
	//flow ½ÃÀÛ!
	int total = 0, F = 0;
	while (1) {
		int prev[ALL_V], dist[ALL_V];
		bool InQ[ALL_V];
		queue<int> Que;
		fill(prev, prev + ALL_V, -1);
		fill(dist, dist + ALL_V, INF);
		fill(InQ, InQ + ALL_V, false);
		Que.push(S);
		dist[S] = 0;
		InQ[S] = true;
		while (Que.size() != 0) {
			int curr = Que.front();
			Que.pop();
			InQ[curr] = false;
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + w[curr][next]) {
					dist[next] = dist[curr] + w[curr][next];
					prev[next] = curr;
					if (InQ[next] == false) {
						Que.push(next);
						InQ[next] = true;
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
			F += flow * w[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total++;
	}
	printf("%d\n%d", total, F);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
#define t_size 404
#define INF 9999999
using namespace std;

int c[t_size][t_size], s, e, f[t_size][t_size], visit[t_size];
int main() {
	vector<int> vertex[t_size];
	int n, p, total = 0;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < p; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}

	s = 1, e = 2;

	while (1) {

		int prev[t_size];
		fill(prev, prev + t_size, -1);
		queue<int> Que;
		Que.push(s);

		while (Que.size() != 0) {
			int curr = Que.front();
			Que.pop();

			for (int next : vertex[curr]) {
				if (c[curr][next] == 0) c[curr][next] = 1;

				if (prev[next] == -1 && c[curr][next] - f[curr][next] > 0 && visit[next] == 0) {
					Que.push(next);
					prev[next] = curr;
					if (next == e) break;
				}
			}
		}

		if (prev[e] == -1) break;
		int F = INF;
		for (int i = e; i != s; i = prev[i]) {
			F = min(F, c[prev[i]][i] - f[prev[i]][i]);
			visit[prev[i]] = 1;
		}

		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += F;
			f[i][prev[i]] -= F;
		}

		total += F;
	}

	printf("%d", total);
}
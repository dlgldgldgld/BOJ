#include<cstring>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#define m_size 403
using namespace std;
const int INF = 1e9;

int c[m_size][m_size], f[m_size][m_size];
int st, ed;
vector<int> vertex[m_size];
int main(void) {
	int n, m, total = 0;
	scanf("%d %d", &n, &m);
	st = n + m + 1, ed = n + m + 2;
	for (int i = 0; i < n; i++) {
		int k, tmp;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			tmp -= 1;
			vertex[i].push_back(tmp + n);
			vertex[tmp + n].push_back(i);
			c[i][tmp + n] += 1;
		}
		vertex[st].push_back(i);
		c[st][i] += 1;
	}
	for (int i = 0; i < m; i++) {
		c[i + n][ed] += 1;
		vertex[i + n].push_back(ed);
		vertex[ed].push_back(i + n);
	}
	while (1) {
		int prev[m_size];
		fill(prev, prev + m_size, -1);
		queue<int> Q;
		Q.push(st);
		while (Q.size() != 0) {
			int curr = Q.front();
			Q.pop();
			for (int next : vertex[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					prev[next] = curr;
					Q.push(next);
					if (prev[ed] != -1) break;
				}
			}

		}
		if (prev[ed] == -1) break;

		int w = INF;
		for (int i = ed; i != st; i = prev[i]) {
			w = min(w, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = ed; i != st; i = prev[i]) {
			f[prev[i]][i] += w;
			f[i][prev[i]] -= w;
		}
		total += w;
	}
	printf("%d\n", total);
}
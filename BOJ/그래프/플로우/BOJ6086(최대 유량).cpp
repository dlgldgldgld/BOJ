#include<cstring>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1e9;
int atoi(char c) {
	int value = (int)c - 65;
	if (value > 25) value -= 6;
	return value;
}

int c[53][53], f[53][53];
vector<int> vertex[53];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b;
		int w;
		scanf(" %c %c %d", &a, &b, &w);
		a = atoi(a), b = atoi(b);
		c[a][b] += w;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	int total = 0, st = 0, ed = 25;
	while (1) {
		int prev[53];
		memset(prev, -1, sizeof(prev));
		queue<int> Q;
		Q.push(st);
		while (Q.size() != 0) {
			int curr = Q.front();
			Q.pop();
			for (int next : vertex[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr;
					if (next == ed) break;
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
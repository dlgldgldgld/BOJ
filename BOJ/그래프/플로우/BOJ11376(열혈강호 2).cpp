#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAX = 2000;
int employ[MAX], work[MAX];
vector<int> adj[MAX];
bool visited[MAX];
bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (work[b] == -1 || !visited[work[b]] && dfs(work[b])) {
			work[b] = a;
			employ[a] = b;
			return true;
		}
	}
	return false;
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k, tmp;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			adj[2 * i].push_back(tmp - 1);
			adj[2 * i + 1].push_back(tmp - 1);
		}
	}
	fill(employ, employ + 2 * n, -1);
	fill(work, work + m, -1);

	int match = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (employ[i] == -1) {
			fill(visited, visited + 2 * n, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d", match);
	return 0;
}
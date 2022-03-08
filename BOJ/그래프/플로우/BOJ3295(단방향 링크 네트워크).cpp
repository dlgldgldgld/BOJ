#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAX = 1001;
vector<int> adj[MAX];
int left[MAX], right[MAX];
bool visited[MAX];
bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (right[b] == -1 || !visited[right[b]] && dfs(right[b])) {
			left[a] = b;
			right[b] = a;
			return true;
		}
	}
	return false;
}
int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
		fill(left, left + n, -1);
		fill(right, right + n, -1);
		int match = 0;
		for (int i = 0; i < n; i++) {
			if (left[i] == -1) {
				fill(visited, visited + n, false);
				if (dfs(i)) match++;
			}
		}
		printf("%d\n", match);
	}
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1000;

int Book[MAX], Student[MAX];
vector<int> adj[MAX];
bool visited[MAX];
bool dfs(int a) {
	visited[a] = true;
	for (int next : adj[a]) {
		if (Student[next] == -1 || !visited[Student[next]] && dfs(Student[next])) {
			Book[a] = next;
			Student[next] = a;
			return true;
		}
	}
	return false;
}
int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) adj[i].clear();

		for (int i = 0; i < M; i++) {
			int k_1, k_2;
			scanf("%d %d", &k_1, &k_2);
			for (int j = k_1 - 1; j <= k_2 - 1; j++) {
				adj[j].push_back(i);
			}
		}
		int match = 0;
		fill(Book, Book + N, -1);
		fill(Student, Student + M, -1);
		for (int i = 0; i < N; i++) {
			if (Book[i] == -1) {
				fill(visited, visited + N, false);
				if (dfs(i)) match++;
			}
		}
		printf("%d\n", match);
	}
}
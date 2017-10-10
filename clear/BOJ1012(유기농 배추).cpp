#include<cstdio>
#include<cstring>
using namespace std;

int n, m, k;
int board[51][51], visit[51][51];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
void dfs(int y, int x) {
	if (visit[y][x] == 1) return;
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i], next_x = x + dx[i];
		if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n) {
			if (board[next_y][next_x] == 1) {
				dfs(next_y, next_x);
			}
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d %d %d", &n, &m, &k);
		memset(board, -1, sizeof(board));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			board[b][a] = 1;
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
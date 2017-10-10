#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 1e9;
int n;
int board[101][101], dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int visit[101][101];
void dfs(int y, int x, int h) {
	if (visit[y][x] == 1) return;
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i], next_x = x + dx[i];
		if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < n) {
			if (board[next_y][next_x] > h) {
				dfs(next_y, next_x, h);
			}
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		memset(visit, 0, sizeof(visit));
		int tmp = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (board[y][x] > i && visit[y][x] == 0) {
					tmp++;
					dfs(y, x, i);
				}
			}
		}
		ans = max(ans, tmp);
	}
	printf("%d", ans);
	return 0;
}
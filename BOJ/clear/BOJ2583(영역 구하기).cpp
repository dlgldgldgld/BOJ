#include<cstdio>
#include<algorithm>
using namespace std;
int board[101][101], ans_value[101];
int n, m, k;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
int dfs(int x, int y) {
	if (x<0 || x > m || y < 0 || y > n) return 0;
	board[x][y] = 1;
	int ret = 0;
	for (int j = 0; j < 4; j++) {
		int next_x = x + dx[j], next_y = y + dy[j];
		if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n &&board[next_x][next_y] == 0) {
			ret += dfs(next_x, next_y) + 1;
		}
	}
	return ret;
}
int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				board[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				ans_value[ans++] = dfs(i, j) + 1;
			}
		}
	}
	sort(ans_value, ans_value + ans);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d ", ans_value[i]);
	}
}
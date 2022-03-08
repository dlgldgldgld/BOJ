#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<utility>
using namespace std;
int map[301][301];
int visit[301][301];
int n, m;
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
void bfs(int y, int x) {
	if (visit[y][x] == 1) return;
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i], next_x = x + dx[i];
		if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m) {
			if (map[next_y][next_x] != 0) {
				bfs(next_y, next_x);
			}
		}
	}
}

void melt() {
	int M[301][301];
	memset(M, 0, sizeof(M));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int next_y = i + dy[k], next_x = j + dx[k];
					if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m) {
						if (map[next_y][next_x] == 0) {
							M[i][j]++;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] -= M[i][j];
			if (map[i][j] < 0) map[i][j] = 0;
		}
	}
}
int main(void) {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int count = 0;; count++) {
		int k = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && visit[i][j] == 0)
				{
					k++;
					bfs(i, j);
				}
				if (k == 2) {
					printf("%d", count);
					return 0;
				}
			}
		}
		if (k == 0) {
			printf("0");
			return 0;
		}
		melt();
	}
}
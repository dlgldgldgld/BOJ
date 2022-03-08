#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
struct Node {
	int y, x, d;
	Node(int a, int b, int c) : y(a), x(b), d(c) { };
};
int board[1001][1001], visit[1001][1001];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(visit, 0, sizeof(visit));
	queue<Node> Que;
	int tomato = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) {
				Que.push(Node(i, j, 0));
			}
			if (board[i][j] == 1 || board[i][j] == 0) {
				tomato++;
			}
		}
	}
	int ans = 0;
	while (Que.size() != 0) {
		Node curr = Que.front();
		int y = curr.y, x = curr.x, d = curr.d;
		Que.pop();
		if (visit[y][x]) continue;
		ans = max(ans, d);
		visit[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i], next_x = x + dx[i];
			if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n) {
				if (board[next_y][next_x] == 0) {
					Que.push(Node(next_y, next_x, d + 1));
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 1) {
				tomato--;
			}
		}
	}
	if (tomato == 0) {
		printf("%d", ans);
	}
	else if (tomato == n*m) {
		printf("0");
	}
	else {
		printf("-1");
	}
	return 0;
}
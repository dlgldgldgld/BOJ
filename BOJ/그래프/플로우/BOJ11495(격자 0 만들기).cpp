#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1e9;
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int C[2505][2505], F[2505][2505], board[50][50], st, ed, p[2505];
vector<int> vertex[2505];
int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(C, 0, sizeof(C));
		memset(F, 0, sizeof(F));
		memset(board, 0, sizeof(board));
		for (int j = 0; j < 2505; j++) vertex[j].clear();

		int n, m, ans = 0;
		scanf("%d %d", &n, &m);
		st = n*m + 1, ed = n*m + 2;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				scanf("%d", &board[y][x]);
				ans += board[y][x];
				if (y % 2 == 0) {
					if ((y + x) % 2 == 0) {
						for (int k = 0; k < 4; k++) {
							if (y + dy[k] >= 0 && y + dy[k] < n && x + dx[k] >= 0 && x + dx[k] < m) {
								vertex[y*m + x].push_back((y + dy[k]) * m + x + dx[k]);
								C[y*m + x][(y + dy[k]) * m + x + dx[k]] = INF;
								vertex[(y + dy[k]) * m + x + dx[k]].push_back(y*m + x);
							}
						}
						C[st][y*m + x] += board[y][x];
						vertex[st].push_back(y*m + x);
						vertex[y*m + x].push_back(st);
					}
					else {
						C[y*m + x][ed] += board[y][x];
						vertex[y*m + x].push_back(ed);
						vertex[ed].push_back(y*m + x);
					}
				}
				else {

					if ((y + x) % 2 == 1) {
						C[y*m + x][ed] += board[y][x];
						vertex[y*m + x].push_back(ed);
						vertex[ed].push_back(y*m + x);
					}
					else {
						for (int k = 0; k < 4; k++) {
							if (y + dy[k] >= 0 && y + dy[k] < n && x + dx[k] >= 0 && x + dx[k] < m) {
								vertex[y*m + x].push_back((y + dy[k]) * m + x + dx[k]);
								C[y*m + x][(y + dy[k]) * m + x + dx[k]] = INF;
								vertex[(y + dy[k]) * m + x + dx[k]].push_back(y*m + x);
							}
						}
						C[st][y*m + x] += board[y][x];
						vertex[st].push_back(y*m + x);
						vertex[y*m + x].push_back(st);
					}

				}
			}
		}

		int total = 0;
		while (1) {
			fill(p, p + 2505, -1);
			queue<int> Que;
			Que.push(st);
			while (Que.size() != 0) {
				int curr = Que.front();
				Que.pop();

				for (int next : vertex[curr]) {
					if (C[curr][next] - F[curr][next] > 0 && p[next] == -1) {
						Que.push(next);
						p[next] = curr;
						if (next == ed) break;
					}
				}
			}
			if (p[ed] == -1) break;
			int flow = INF;
			for (int i = ed; i != st; i = p[i]) {
				flow = min(flow, C[p[i]][i] - F[p[i]][i]);
			}
			for (int i = ed; i != st; i = p[i]) {
				F[p[i]][i] += flow;
				F[i][p[i]] -= flow;
			}
			total += flow;
		}

		ans -= total;
		printf("%d\n", ans);
	}
}
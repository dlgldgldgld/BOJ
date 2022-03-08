#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
struct Node {
	int y, x, move;
	Node(int a, int b, int c) : y(a), x(b), move(c) { }
};
int visit[301][301];
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 }, dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int l;
		scanf("%d", &l);
		int s_x, s_y, d_x, d_y;
		int ans = 0;
		scanf("%d %d", &s_x, &s_y);
		scanf("%d %d", &d_x, &d_y);
		queue<Node> Que;
		Que.push(Node(s_y, s_x, 0));
		memset(visit, 0, sizeof(visit));
		while (Que.size() != 0) {
			Node curr = Que.front();
			int curr_y = curr.y;
			int curr_x = curr.x;
			int move = curr.move;
			if (curr_y == d_y && curr_x == d_x) {
				ans = move;
				break;
			}
			Que.pop();
			if (visit[curr_y][curr_x]) continue;
			visit[curr_y][curr_x] = 1;
			for (int i = 0; i < 8; i++) {
				int next_y = curr_y + dy[i];
				int next_x = curr_x + dx[i];
				if (next_y >= 0 && next_y < l && next_x >= 0 && next_x < l) {
					Que.push(Node(next_y, next_x, move + 1));
				}
			}
		}
		printf("%d\n", ans);
	}
}
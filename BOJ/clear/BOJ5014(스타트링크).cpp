#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
bool visit[1000001];
int main(void) {
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	queue<pii> Que;
	Que.push(pii(S, 0));
	fill(visit, visit + 1000001, false);
	int ans = INF;
	while (Que.size() != 0) {
		pii curr = Que.front();
		int curr_floor = curr.first;
		int d = curr.second;
		if (curr_floor == G) { ans = d; break; }
		Que.pop();
		if (visit[curr_floor]) continue;
		visit[curr_floor] = true;

		if (curr_floor + U <= F) {
			Que.push(pii(curr_floor + U, d + 1));
		}
		if (curr_floor - D >= 1) {
			Que.push(pii(curr_floor - D, d + 1));
		}
	}
	if (ans == INF) {
		printf("use the stairs");
	}
	else printf("%d", ans);
}
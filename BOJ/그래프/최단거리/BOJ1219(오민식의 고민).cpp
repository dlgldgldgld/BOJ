#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, long long> pii;
vector<pii> vertex[101];
long long dist[101], consume[101];
const long long INF = 1e11;
int main(void) {
	int n, st, ed, m;
	scanf("%d %d %d %d", &n, &st, &ed, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		vertex[a].push_back(pii(b, -c));
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &consume[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < vertex[i].size(); j++) {
			vertex[i].at(j).second += consume[vertex[i].at(j).first];
		}
	}
	fill(dist, dist + n, -INF);
	dist[st] = consume[st];
	queue<int> Que;
	bool cycle = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (pii k : vertex[j]) {
				int next = k.first;
				long long d = k.second;
				if (dist[j] != -INF && dist[next] < dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == n - 1) {
						Que.push(next);
						cycle = true;
					}
				}
			}
		}
	}
	bool visit[101], In_cycle = false;
	memset(visit, 0, sizeof(visit));
	while (Que.size() != 0) {
		int curr = Que.front();
		Que.pop();
		if (curr == ed) { In_cycle = true; break; }
		if (visit[curr]) continue;
		visit[curr] = true;
		for (pii next : vertex[curr]) {
			Que.push(next.first);
		}
	}
	if (cycle && In_cycle) {
		printf("Gee");
	}
	else if (dist[ed] == -INF) {
		printf("gg");
	}
	else {
		printf("%lld", dist[ed]);
	}
}
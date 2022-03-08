#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef pair<double, double> P;
typedef pair<int, double> pib;
const double walk_speed = 5;
const double boom_second = 2;
const double boom_distance = 50;
const double INF = 10000000000;
vector<pib> vertex[104];
P In[104];
double dist[104];
bool visit[104];
double get_distance(P a, P b) {
	double dis_x = abs(b.first - a.first);
	double dis_y = abs(b.second - a.second);
	return sqrt(dis_x*dis_x + dis_y*dis_y);
}

struct cmp {
	bool operator() (pib a, pib b) {
		return a.second > b.second;
	}
};
int main(void) {
	double sx, sy, dx, dy;
	scanf("%lf %lf %lf %lf", &sx, &sy, &dx, &dy);
	int n;
	scanf("%d", &n);
	In[1].first = sx; In[1].second = sy;
	for (int i = 2; i <= n + 1; i++) {
		scanf("%lf %lf", &In[i].first, &In[i].second);
	}
	In[n + 2].first = dx, In[n + 2].second = dy;
	for (int i = 1; i <= n + 2; i++) {
		for (int j = 1; j <= n + 2; j++) {
			if (i == j) continue;
			double dis = get_distance(In[i], In[j]);
			if (i == 1 || i == n + 2) {
				vertex[i].pb(mp(j, dis / walk_speed));
			}
			else {
				vertex[i].pb(mp(j, min(dis / walk_speed, abs(dis - boom_distance) / walk_speed + boom_second)));
			}
		}
	}
	int st = 1, ed = n + 2;
	priority_queue<pib, vector<pib>, cmp> Que;
	fill(dist, dist + n + 3, INF);
	Que.push(pib(st, 0));
	dist[st] = 0;
	while (Que.size() != 0) {
		pib tmp = Que.top();
		Que.pop();
		if (visit[tmp.first]) continue;
		visit[tmp.first] = 1;
		int curr = tmp.first;
		for (pib i : vertex[curr]) {
			int next = i.first;
			double d = i.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				Que.push(pib(next, dist[next]));
			}
		}
	}
	printf("%f", dist[n + 2]);
}
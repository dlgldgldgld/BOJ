#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define p_size 1000
#define v_size 100
using namespace std;
const int INF = 1e9;
const int k_size = p_size*v_size + v_size + 2;

struct Edge {
	int to, c, f;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int u, int w) : to(u), c(w), f(0), dual(nullptr) {}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int pig[p_size], p[k_size];
vector<Edge *> vertex[k_size];
int main() {
	int n, m, k;
	scanf("%d %d", &m, &n);
	int st = m*n + n + 1, ed = m*n + n + 2;
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		Edge* e1 = new Edge(i, k);
		Edge* e2 = new Edge(st, 0);
		e1->dual = e2;
		e2->dual = e1;
		vertex[st].push_back(e1);
		vertex[i].push_back(e2);
	}

	for (int i = 0; i < n; i++) {
		int routine;
		if (i != n - 1) {
			for (int j = 0; j < m; j++) {
				Edge * e1 = new Edge((i + 1)*m + j, INF);
				Edge * e2 = new Edge((i)*m + j, 0);
				e1->dual = e2;
				e2->dual = e1;
				vertex[i*m + j].push_back(e1);
				vertex[(i + 1)*m + j].push_back(e2);
			}
		}
		scanf("%d", &routine);
		if (i != n - 1) {
			vector<int> ee;
			for (int j = 0; j < routine; j++) {
				int tmp;
				scanf("%d", &tmp);
				ee.push_back(tmp - 1);
			}
			for (int p = 0; p < ee.size(); p++) {
				Edge * e3 = new Edge(m*n + i, INF);
				Edge * e4 = new Edge((i)*m + ee[p], 0);
				e3->dual = e4;
				e4->dual = e3;
				vertex[(i)*m + ee[p]].push_back(e3);
				vertex[m*n + i].push_back(e4);
				for (int q = 0; q < ee.size(); q++) {
					Edge * e1 = new Edge((i + 1)*m + ee[q], INF);
					Edge * e2 = new Edge((i)*m + ee[p], 0);
					e1->dual = e2;
					e2->dual = e1;
					vertex[(i)*m + ee[p]].push_back(e1);
					vertex[(i + 1)*m + ee[q]].push_back(e2);
				}
			}
		}
		else {
			vector<int> ee;
			for (int j = 0; j < routine; j++) {
				int tmp;
				scanf("%d", &tmp);
				ee.push_back(tmp - 1);
			}
			for (int p = 0; p < ee.size(); p++) {
				Edge * e3 = new Edge(m*n + i, INF);
				Edge * e4 = new Edge((i)*m + ee[p], 0);
				e3->dual = e4;
				e4->dual = e3;
				vertex[(i)*m + ee[p]].push_back(e3);
				vertex[m*n + i].push_back(e4);
			}
		}
		int tmp_2;
		scanf("%d", &tmp_2);
		Edge * e1 = new Edge(ed, tmp_2);
		Edge * e2 = new Edge(m*n + i, 0);
		e1->dual = e2;
		e2->dual = e1;
		vertex[m*n + i].push_back(e1);
		vertex[ed].push_back(e2);

	}
	// flow Ω√¿€
	int total = 0;
	while (1) {
		fill(p, p + k_size, -1);
		Edge *p_edge[k_size] = { nullptr };
		queue<int> Que;
		Que.push(st);
		while (Que.size() != 0) {
			int curr = Que.front();
			Que.pop();
			for (Edge *e : vertex[curr]) {
				int next = e->to;
				if (e->spare() > 0 && p[next] == -1) {
					p[next] = curr;
					p_edge[next] = e;
					Que.push(next);
				}
			}
		}
		if (p[ed] == -1) break;
		int f = INF;
		for (int i = ed; i != st; i = p[i]) {
			f = min(f, p_edge[i]->spare());
		}
		for (int i = ed; i != st; i = p[i]) {
			p_edge[i]->addFlow(f);
		}
		total += f;
	}

	printf("%d\n", total);
}

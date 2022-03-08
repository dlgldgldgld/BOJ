#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
#include<fstream>
#define m_size 262144
using namespace std;
int cnt[m_size * 2 + 1], t_size = m_size;
int idx_cnt[m_size];
void update(int idx, int value) {
	idx += m_size;
	cnt[idx] = value;
	while (idx > 1) {
		idx /= 2;
		cnt[idx] = cnt[idx * 2] + cnt[idx * 2 + 1];
	}
}

int sum(int L, int R, int Node_num, int T_L, int T_R) {
	if (L > T_R || T_L > R) return 0;
	if (L <= T_L && T_R <= R) return cnt[Node_num];

	int mid = (T_L + T_R) / 2;
	return sum(L, R, Node_num * 2, T_L, mid) + sum(L, R, Node_num * 2 + 1, mid + 1, T_R);
}
int main() {
	int T;
	cin >> T;
	while (T-- != 0) {
		int n, m, tmp, next_idx;
		memset(cnt, 0, sizeof(cnt));
		memset(idx_cnt, 0, sizeof(idx_cnt));
		scanf("%d %d", &n, &m);
		next_idx = m_size / 2 - 1;
		for (int i = 0; i < n; i++) {
			idx_cnt[i + 1] = i + m_size / 2;
			update(i + m_size / 2, 1);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			printf("%d ", sum(0, idx_cnt[tmp] - 1, 1, 0, t_size - 1));
			update(idx_cnt[tmp], 0);
			update(next_idx, 1);
			idx_cnt[tmp] = next_idx--;
		}
		printf("\n");
	}
}
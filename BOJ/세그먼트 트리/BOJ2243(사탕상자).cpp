#include<cstdio>
#include<algorithm>
#define t_size 1048576
using namespace std;

long long candy[t_size * 2 + 1];

void update(int idx, long long value) {
	idx += t_size;
	candy[idx] += value;
	while (idx > 1) {
		idx /= 2;
		candy[idx] = candy[idx * 2] + candy[idx * 2 + 1];
	}
}

int binary_search(int rank, int idx) {
	if (rank <= candy[idx] && idx > t_size) return idx - t_size;
	else if (idx >= t_size * 2 || rank <= 0) return 0;

	int r = 0;
	if (candy[idx * 2] < rank) {
		r = max(r, binary_search(rank - candy[idx * 2], idx * 2 + 1));
	}
	else {
		r = max(r, binary_search(rank, idx * 2));
	}
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; long long c;
		scanf("%d", &a);
		if (a == 1) { // b¹ø¤Š ¼øÀ§ »çÅÁ »©³»´Â °æ¿ì
			scanf("%d", &b);
			int ans = binary_search(b, 1);
			printf("%d\n", ans);
			update(ans, -1);
		}
		else { // b¸À »çÅÁÀ» c°³ ³Ö´Â °æ¿ì
			scanf("%d %lld", &b, &c);
			update(b, c);
		}
	}
}
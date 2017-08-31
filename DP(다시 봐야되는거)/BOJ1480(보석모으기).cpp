#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

int n, m, c, jam[13], DP[11][21][1 << 13];

int process(int A, int B, int C) {
	if (A == m) return 0;
	int &ret = DP[A][B][C];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, process(A + 1, 0, C));
	for (int i = 0; i < n; i++) {
		if (C & (1 << i)) {
			continue;
		}
		else if (c - B >= jam[i]) {
			ret = max(ret, process(A, B + jam[i], C | (1 << i)) + 1);
		}
	}
	return ret;
}
int main() {
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) scanf(" %d", &jam[i]);
	memset(DP, -1, sizeof(DP));
	printf("%d", process(0, 0, 0));
}
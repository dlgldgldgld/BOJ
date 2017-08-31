#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;
//FILE * inp = fopen("Test.txt", "r");
int DP[2001][2001], A[2001], B[2001], n;

int cal_DP(int a, int b) {
	if (a == n || b == n) {
		return 0;
	}

	int &ret = DP[a][b];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, cal_DP(a + 1, b));
	ret = max(ret, cal_DP(a + 1, b + 1));
	if (A[a] > B[b]) ret = max(ret, cal_DP(a, b + 1) + B[b]);

	return ret;
}
int main() {
	scanf("%d", &n);
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < n; i++) scanf(" %d", &A[i]);
	for (int i = 0; i < n; i++) scanf(" %d", &B[i]);

	printf("%d", cal_DP(0, 0));
}
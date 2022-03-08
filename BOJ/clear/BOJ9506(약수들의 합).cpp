#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> adj[100001];
int main(void) {
	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (i*j > 100000) break;
			adj[i*j].push_back(i);
		}
	}
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == -1) return 0;
		int k = 0;
		for (int N : adj[n]) {
			if (N == n) break;
			k += N;
		}
		if (k == n) {
			printf("%d =", n);
			for (int N : adj[n]) {
				printf(" %d", N);
				k -= N;
				if (k == 0) break;
				printf(" +");
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}
	}
}
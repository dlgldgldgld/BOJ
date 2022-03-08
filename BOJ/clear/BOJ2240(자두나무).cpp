#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int DP[1001][31], In[1001];
int main() {
	int T, W;
	cin >> T >> W;
	for (int i = 0; i < T; i++) cin >> In[i];
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= W; j++) {
			if (i + 1 >= j) {
				DP[i][j] = max(DP[i][j], DP[i - 1][j]);
				if (j - 1 >= 0) {
					DP[i][j] = max(DP[i][j], DP[i - 1][j - 1]);
				}
				if (j % 2 == In[i] - 1) DP[i][j] += 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++) {
		ans = max(DP[T - 1][i], ans);
	}
	cout << ans;
	return 0;
}
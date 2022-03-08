#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define m_size 110
#define INF 99999999
using namespace std;

int C[m_size][m_size], In[m_size], DP[m_size][m_size];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> In[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			DP[i][j] = -INF;
			if (i == j) C[i][j] = In[i];
			else if (i < j) {
				C[i][j] = C[i][j - 1] + In[j];
			}
		}
	}

	for (int k = 1; k <= m; k++) {
		for (int i = k; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (k == 1) {
					if (i == 1) {
						DP[i][k] = In[i];
					}
					else {
						DP[i][k] = max(DP[i][k], DP[i - 1][k - 1] + C[j][i]);
						DP[i][k] = max(DP[i][k], DP[i - 1][k]);
					}
				}
				else if (j + 1 <= i && j - 1 > 0 && j - 1 >= (k - 1) * 2 - 1) {
					DP[i][k] = max(DP[i][k], DP[j - 1][k - 1] + C[j + 1][i]);
					DP[i][k] = max(DP[i][k], DP[i - 1][k]);
				}
			}
		}
	}

	int ans = -INF;
	for (int i = 2 * m - 1; i <= n; i++) {
		ans = max(ans, DP[i][m]);
	}
	cout << ans;
}
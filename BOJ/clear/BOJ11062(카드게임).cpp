#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<utility>
#define m_size 1001
#define INF 99999999
using namespace std;

int DP[m_size][m_size], C[m_size][m_size], In[m_size];

int main() {

	int T;
	cin >> T;
	while (T-- != 0) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> In[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i <= j) {
					C[i][j] = C[i][j - 1] + In[j];
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - (i - 1); j++) {
				int a = j, b = j + (i - 1);
				if (a == b) DP[a][b] = C[a][b];
				else DP[a][b] = max(C[a][b - 1] - DP[a][b - 1] + C[b][b], C[a][a] + C[a + 1][b] - DP[a + 1][b]);
			}
		}
		cout << DP[1][n] << endl;
	}
}

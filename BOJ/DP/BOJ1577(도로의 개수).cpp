#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

unsigned long long DP[101][101];
vector<pair<int, int>> Nope[101][101];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > c) swap(a, c);
		if (b > d) swap(b, d);
		Nope[d][c].push_back(make_pair(b, a));
	}
	DP[0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			int ck = 0;
			if (i - 1 >= 0) {
				for (int t = 0; t < Nope[i][j].size(); t++) {
					if (Nope[i][j].at(t).first == i - 1 && Nope[i][j].at(t).second == j) {
						ck = 1; break;
					}
				}
				if (ck != 1) DP[i][j] += DP[i - 1][j];
			}
			ck = 0;
			if (j - 1 >= 0) {
				for (int t = 0; t < Nope[i][j].size(); t++) {
					if (Nope[i][j].at(t).first == i && Nope[i][j].at(t).second == j - 1) {
						ck = 1; break;
					}
				}
				if (ck != 1) DP[i][j] += DP[i][j - 1];
			}
		}
	}

	cout << DP[m][n];
}
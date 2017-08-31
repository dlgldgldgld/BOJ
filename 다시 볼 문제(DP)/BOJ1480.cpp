#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef map<string, bool> M;

int L;
M dp;

bool cal_dp(string S) {
	M::iterator F = dp.find(S);
	if (F != dp.end()) return F->second;
	if (S.size() == 0) return dp[S] = true;
	if (S.size() == 1) return dp[S] = false;

	bool ret = false;

	int i = 0;
	for (int j = i; j <= S.size(); j++) {
		if (j == S.size() || S.at(i) != S.at(j)) {
			if (j - i > 1) {
				ret |= cal_dp(S.substr(0, i) + S.substr(j));
			}
			i = j;
		}
	}
	return dp[S] = ret;
}
int main() {
	int T;
	cin.sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t<T; t++) {
		string S;
		cin >> S;
		cout << cal_dp(S) << endl;
	}
}
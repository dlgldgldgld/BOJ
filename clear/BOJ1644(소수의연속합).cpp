#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
int p[4000001], check[4000010];

vector<ll> prime;
int main() {
	for (int i = 2; i <= 4000000; i++) {
		for (int j = 2; j <= 4000000; j++) {
			if (i*j > 4000000) break;
			p[i*j] = 1;
		}
	}

	for (ll i = 2; i <= 4000000; i++) {
		if (p[i] == 0) prime.push_back(i);
	}

	int s;
	for (int i = 0; i < 283146; i++) {
		s = 0;
		for (int j = i; j < 283146; j++) {
			s += prime[j];
			if (s > 4000000) break;
			check[s]++;
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d", check[n]);
	return 0;
}

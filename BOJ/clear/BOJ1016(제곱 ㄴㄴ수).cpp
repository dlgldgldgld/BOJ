#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
int p[1000001], check[1000010];
vector<ll> prime;
int main() {
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; j <= 1000000; j++) {
			if (i*j >= 1000000) break;
			p[i*j] = 1;
		}
	}

	for (ll i = 2; i <= 1000000; i++) {
		if (i*i > 1000000000000) break;
		if (p[i] == 0) prime.push_back(i*i);
	}

	ll a, b;
	scanf("%lld %lld", &a, &b);

	for (ll k : prime) {
		ll s = -1, k_i;
		s = ((a / k)) * k;
		if (s < a) s += k;
		for (int t = 0;; t++) {
			if (s + t*k > b) break;
			check[s + t*k - a + 1] = 1;
		}
	}
	
	int ans = 0;
	for (ll i = a; i <= b; i++) {
		if (check[i - a + 1] == 0) ans++;
	}

	printf("%d",ans);
	return 0;
}

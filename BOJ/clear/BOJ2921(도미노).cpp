#include<cstdio>
int main(void) {
	int n, ans = 0, j = 1;
	scanf("%d", &n);
	for (int i = n; i >= 0; i--, j++) {
		ans += i*(i + 1);
		ans += i*j;
	}
	printf("%d", ans);
	return 0;
}
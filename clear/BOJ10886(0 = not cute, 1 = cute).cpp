#include<cstdio>
int main(void) {
	int n, z = 0, o = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 1) o++;
		else z++;
	}
	if (o > z) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}
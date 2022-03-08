#include<cstdio>
int main(void) {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int X, Y;
	X = a*e;
	Y = b;
	if (c < e) Y += (e - c)*d;
	if (X < Y) printf("%d", X);
	else printf("%d", Y);
}
#include<stdio.h>

int Board[500][500], Number, Input[500], Sum[500][500];

int mim(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int DP_cal(int a, int b) {
	int i, mim_val = 999999999;

	if (a == b) {
		return Input[a];
	}

	for (i = a; i < b; i++) {
		mim_val = mim(mim_val, Board[a][i] + Board[i + 1][b]);
	}

	Board[a][b] = Sum[a][b] + mim_val;

	return Board[a][b];
}
int main(void) {
	int TestCase, x, y;

	scanf("%d", &TestCase);
	while (TestCase-- != 0) {
		scanf("%d", &Number);
		for (x = 0; x < Number; x++) {
			scanf("%d", &Input[x]);
		}


		for (x = Number - 1; x >= 0; x--) {
			for (y = x; y < Number; y++) {
				if (x == y) {
					Sum[x][y] = Input[x];
				}
				else {
					Sum[x][y] = Input[y] + Sum[x][y - 1];
					Board[x][y] = DP_cal(x, y);
				}
			}
		}
		printf("%d\n", Board[0][Number - 1]);
	}
	return 0;
}
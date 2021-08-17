#include <cstdio>

int g_n;
int g_m;
int g_list[10];

bool isValid( int num, int idx )
{
	for ( int i = 0; i < idx; i++ )
	{
		if ( g_list[i] > num )
		{
			return false;
		}

		if (g_list[i] == num)
		{
			return false;
		}
	}

	return true;
}
void solution( int idx )
{
	if ( idx == g_m )
	{
		for ( int i = 0; i < g_m; i++ )
		{
			printf("%d ", g_list[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= g_n; i++)
	{
		if ( !isValid(i, idx) )
		{
			continue;
		}

		g_list[idx] = i;
		solution(idx + 1);
	}

}

int main(void)
{
	scanf("%d %d", &g_n, &g_m);
	solution(0);
	return 0;
}
#include <cstdio>

int g_array[21];
int g_nums[21];
int g_answer = 0;
void solution( int idx, int c_n, int sum, int s, int n )
{
	if (idx != 0 && s == sum)
	{
		g_answer++;
	}

	if ( idx == n )
	{
		return;
	}

	for ( int i = 0; i < n; i++ )
	{
		if ( i <= c_n )
		{
			continue;
		}

		g_array[idx] = g_nums[i];
		solution(idx + 1, i, sum + g_nums[i], s, n );
	}

	return;
}
int main(void)
{
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &g_nums[i]);
	}

	solution(0, -1, 0, s, n);
	printf("%d", g_answer);
	return 0;
}
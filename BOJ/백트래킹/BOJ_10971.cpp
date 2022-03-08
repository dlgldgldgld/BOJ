#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

int g_n = 0;
int g_maps[11][11];

int g_answer = 2147483647;
int  g_history[11];
bool g_list[11];
bool is_answer = false;

bool is_promising(int idx, int from, int to, int st_pos )
{
	if ( idx < g_n - 1 )
	{
		if ( st_pos == to )
		{
			return false;
		}
	}

	if (   g_maps[from][to] <= 0
		|| g_list[to] == true )
	{
		return false;
	}

	return true;
}

void TSP( int idx, int from, int sum , int st_pos )
{
	if ( idx == g_n )
	{
		g_answer = std::min( g_answer, sum );
		is_answer = true;
		return;
	}

	if (is_answer == true)
	{
		if (sum >= g_answer)
		{
			return;
		}
	}

	for ( int i = 0; i < g_n; i++ )
	{
		if ( idx == -1 )
		{
			TSP(idx + 1, i, 0, i );
			continue;
		}

		if ( !is_promising( idx, from, i, st_pos ) )
		{
			continue;
		}

		g_list[i] = true;
		TSP(idx + 1, i, sum + g_maps[from][i], st_pos);
		g_list[i] = false;
	}

	return;
}

int main(void)
{
	//FILE * inp = fopen("txt/test.txt", "r");
	//fscanf(inp, "%d", &g_n);
	scanf("%d", &g_n);
	for (int i = 0; i < g_n; i++)
	{
		g_list[i] = false;
		for (int j = 0; j < g_n; j++)
		{
			//fscanf(inp, "%d", &g_maps[i][j]);
			scanf("%d", &g_maps[i][j]);
		}
	}
	
	TSP(-1, -1, 0, -1 );
	printf("%d", g_answer);

}

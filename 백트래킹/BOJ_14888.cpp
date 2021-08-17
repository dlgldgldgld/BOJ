#include <cstdio>
#include <limits.h>
#include <algorithm>

int g_n;
int g_list[12];
int g_oper[4];

long long g_min = LLONG_MAX;
long long g_max = LLONG_MIN;

#ifdef HSSHIN_TEST
FILE * inp = fopen("txt/BOJ_14888.txt", "r");
#endif

bool isvalid ( long long val, bool is_max )
{
	if ( is_max == true )
	{
		if (   g_max != LLONG_MIN
			&& g_max > val
			&& g_oper[0] == 0
			&& g_oper[2] == 0 
			&& g_oper[3] == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (   g_min != LLONG_MAX
			&& g_min < val
			&& g_oper[1] == 0
			&& g_oper[2] == 0 
			&& g_oper[3] == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void GetAnswer( int idx, long long val, bool isMaxMode )
{
	if ( idx == g_n )
	{
		if ( isMaxMode ) 
			g_max = std::max( g_max, val );
		else 
			g_min = std::min( g_min, val );
		
		return;
	}

	for ( int i = 0; i < 4; i++ )
	{
		if ( g_oper[i] > 0 )
		{
			long long next_val ;
			switch (i)
			{
			case 0:
				next_val = val + g_list[idx];
				break;
			case 1:
				next_val = val - g_list[idx];
				break;
			case 2:
				next_val = val * g_list[idx];
				break;
			case 3:
				next_val = val / g_list[idx];
				break;
			}

			if ( !isvalid (next_val, isMaxMode ) )
			{
				continue;
			}

			g_oper[i] -= 1;
			GetAnswer(idx + 1, next_val, isMaxMode);
			g_oper[i] += 1;
		}
	}
}

int main(void)
{
#ifdef HSSHIN_TEST
	fscanf(inp,"%d", &g_n);
	for (int i = 0; i < g_n; i++)
	{
		fscanf(inp, "%d", &g_list[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		fscanf(inp, "%d", &g_oper[i]);
	}

#else
	scanf("%d", &g_n);
	for (int i = 0; i < g_n; i++)
	{
		scanf("%d", &g_list[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &g_oper[i]);
	}
#endif

	GetAnswer(1, g_list[0], true  ) ;
	GetAnswer(1, g_list[0], false ) ;
	printf("%lld\n%lld", g_max, g_min );
	
}
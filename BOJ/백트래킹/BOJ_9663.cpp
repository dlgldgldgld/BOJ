#include <cstdio>
#include <cstring>
constexpr int MAX_SIZE = 16;

int g_answer = 0;
int N = 0;
int g_list[ MAX_SIZE ] ;

bool is_promising( int i, int index )
{
	if ( index == 0 )
	{
		return true;
	}

	bool isPromise = true;

	for ( int idx = 0; idx < index; idx++ )
	{
		if ( g_list[idx] == i )
		{
			isPromise = false;
			break;
		}
		if (   ( index - idx ) ==  ( i - g_list[idx] ) 
			|| ( index - idx ) ==  ( g_list[idx] - i ) )
		{
			isPromise = false;
			break;
		}
		
	}
	return isPromise;
}
 
bool N_QUEEN( int index )
{
	if ( index == N )
	{
		g_answer++;
		return true;
	}

	for ( int i = 0; i < N; i++ )
	{
		if ( true == is_promising( i, index ) )
		{
			g_list[index] = i;
			N_QUEEN(index + 1);
			g_list[index] = -1;
		}
		else
		{
			continue;
		}
	}

	return true;
}

int main(void)
{
	memset(g_list, -1, sizeof(int) * MAX_SIZE);
	scanf("%d", &N);
	N_QUEEN(0);
	printf("%d", g_answer);
	return 0;
}
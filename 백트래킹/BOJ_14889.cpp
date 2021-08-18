#include <cstdio>
#include <cstring>
#include <limits>
#include <algorithm>

constexpr int MAX_SIZE = 20;
int g_n;
int g_s[ MAX_SIZE ][ MAX_SIZE ];
bool g_list[ MAX_SIZE ];
int g_answer = 2147483647;
void solution( int cnt , int n )
{
	if( cnt == ( g_n / 2 ) )
	{
		int sum1 = 0;
		int sum2 = 0;
		for( int i = 0 ; i < g_n ; i++ )
		{
			for ( int j = i+1 ; j < g_n; j++ )
			{
				if( g_list[ i ] == true && g_list[ j ] == true )
				{
					sum1 += g_s[ i ][ j ];
					sum1 += g_s[ j ][ i ];
				}

				if( g_list[ i ] == false && g_list[ j ] == false )
				{
					sum2 += g_s[ i ][ j ];
					sum2 += g_s[ j ][ i ];
				}
				
			}
		}

		g_answer = std::min( g_answer , abs( sum1 - sum2 ) );
		return ;
	}

	for( int i = 0; i < g_n ; i++ )
	{
		if( i <= n )
		{
			continue;
		}
		g_list[ i ] = true;
		solution( cnt + 1, i );
		g_list[ i ] = false;
	}

	return;
}

int main( void )
{
	memset( g_list , false , MAX_SIZE ) ;
	scanf( "%d" , &g_n );
	for( int i = 0 ; i < g_n ; i++ )
	{
		for( int j = 0 ; j < g_n; j++ )
		{
			scanf( "%d" , &g_s[ i ][ j ] );
		}
	}
	solution( 0 , -1 );
	printf( "%d" , g_answer );
	return 0;
}
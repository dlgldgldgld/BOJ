#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;


typedef struct pt
{
	int y;
	int x;
	int key;
	int len;

	pt( int _y, int _x , int _key, int _len ) 
		: y(_y), x(_x), key(_key), len(_len)
	{

	}
};

int d_y[4] = {0, 0, -1, 1};
int d_x[4] = {-1, 1, 0, 0 };
int n, m;
int g_answer = 99999999;

const int UPPER_ALPHABET = 65;
const int LOWER_ALPHABET = 97;

bool visited[51][51][1 << 6];
char maps[51][51];


void bfs ( int s_y, int s_x )
{
	queue<pt> search_queue;

	search_queue.emplace( pt( s_y, s_x, 0, 0 ) );
	
	int n_x = 0;
	int n_y = 0;
	int key = 0;
	int new_key = 0;
	int len = 0;

	while ( !search_queue.empty( ) )
	{
		pt curr_pos = search_queue.front();
		search_queue.pop();
		key = curr_pos.key;
		len = curr_pos.len;
		
		if ( visited[curr_pos.y][curr_pos.x][key] == true )
		{
			continue;
		}
		visited[curr_pos.y][curr_pos.x][key] = true;

		if (maps[curr_pos.y][curr_pos.x] == '1' )
		{
			g_answer = std::min ( g_answer, len ) ;
			continue;
		}

		for ( int i = 0; i < 4; i++ )
		{
			n_x = curr_pos.x + d_x[i];
			n_y = curr_pos.y + d_y[i];
			new_key = key;

			if ( n_x == 0 || n_y == 0 || n_x == m + 1 || n_y == n + 1 )
			{
				continue;
			}

			// 벽이면 안감.
			if ( maps[n_y][n_x] == '#' )
			{
				continue;
			}

			if (   maps[n_y][n_x] >= LOWER_ALPHABET 
				&& maps[n_y][n_x] <= LOWER_ALPHABET + 5 )
			{
				// 소문자인경우
				new_key = new_key | ( 1 << maps[n_y][n_x] - LOWER_ALPHABET ) ;
			}
			else if (   maps[n_y][n_x] >= UPPER_ALPHABET 
				     && maps[n_y][n_x] <= UPPER_ALPHABET + 5)
			{
				// 대문자인 경우
				int key_value = (1 << maps[n_y][n_x] - UPPER_ALPHABET);
				if ( ( key & key_value ) != ( key_value ) )
				{
					// 열쇠 없으면 못들어감.					
					continue;
				}
			}

			search_queue.emplace( pt ( n_y, n_x, new_key, len + 1 ) );
		}
	}
}

int main(void)
{
	
	int s_y, s_x;
	//FILE * inp = fopen("test.txt", "r");
	//fscanf(inp, "%d %d\n", &n, &m);
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//fscanf(inp, "%c", &maps[i][j]);
			scanf("%c", &maps[i][j]);

			if (maps[i][j] == '0')
			{
				s_x = j;
				s_y = i;
			}
		}
		//fscanf(inp, "\n");
		
		if (i == n)
		{
			break;
		}
		scanf("\n");
	}
	
	bfs( s_y, s_x );

	if ( g_answer == 99999999 )
	{
		g_answer = -1;
	}

	printf("%d", g_answer);
	return 0;
}
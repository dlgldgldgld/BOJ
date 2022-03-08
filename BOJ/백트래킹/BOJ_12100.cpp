#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int g_answer = 0;
int dx[4] = { -1 , 1 , 0 , 0 };
int dy[4] = { 0 , 0 , -1 , 1 };

enum class eDirection
{
	LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3
};

class map_2048
{
private :
	int m_n = 0;
	bool is_merge[21][21];
	void setNextPos(int const & y, int const & x, eDirection dir);
	
public :
	int m_map[21][21];

	map_2048()
	{
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				m_map[i][j] = 0;
				is_merge[i][j] = false;
			}
		}
	}

	int GetMaxValue()
	{
		int maxValue = 0;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_n; j++)
			{
				maxValue = std::max(maxValue, m_map[i][j]);
			}
		}
		return maxValue;
	}
	void ShowMap()
	{
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_n; j++)
			{
				printf("%d ", m_map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	void ResetMergeFlag()
	{
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_n; j++)
			{
				is_merge[i][j] = false;
			}
		}

	}

	void SetN(int _n);
	map_2048 upMap();
	map_2048 rightMap();
	map_2048 leftMap();
	map_2048 downMap();

};

void map_2048::setNextPos(int const & y, int const & x, eDirection dir)
{
	int  c_number = m_map[y][x];
	int  f_number = -1;

	int  movDir = static_cast<int> (dir);
	int  move_cnt = 0;

	int my = y;
	int mx = x;

	bool is_moved = false;

	for (int i = 1; i < m_n; i++)
	{
		my = y + dy[movDir] * (i);
		mx = x + dx[movDir] * (i);

		// 아무것도 걸리는 것 없이 끝에 도착한 경우.
		// => 바로 이동시킴.
		if (my == m_n || my == -1 || mx == m_n || mx == -1)
		{	
			if ( move_cnt > 0 )
			{
				m_map[my - dy[movDir]][mx - dx[movDir]] = m_map[y][x];
				m_map[y][x] = 0;
			}
			break;
		}

		if ( m_map[my][mx] != 0 )
		{
			// 만약 값이 같다면 합침.
			if (   m_map[my][mx] == c_number 
				&& is_merge[my][mx] == false )
			{
				is_merge[ my ][ mx ] = true;
				m_map[my][mx] *= 2;
				m_map[y][x] = 0;
			}
			else
			{
				// 다르다면 그냥 이동.
				if ( move_cnt != 0 )
				{
					m_map[ my - dy[ movDir ] ][ mx - dx[ movDir ] ] = m_map[y][x] ;
					m_map[ y ][ x ] = 0 ;	
				}
			}
			break;
		}
		move_cnt++;
	}

	return;
}

void map_2048::SetN(int _n)
{
	m_n = _n;
}

map_2048 map_2048::upMap()
{
	ResetMergeFlag();
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (m_map[i][j] != 0)
			{
				
				setNextPos( i, j, eDirection::UP ) ;
			}
		}
	}
	return *this;
}


map_2048 map_2048::rightMap()
{
	ResetMergeFlag();
	for ( int j = m_n - 1; j >= 0 ; j-- )
	{
		for ( int i = 0; i < m_n; i++ )
		{
			if (m_map[i][j] != 0)
			{
				setNextPos(i, j, eDirection::RIGHT);
			}
		}
	}
	return *this;
}

map_2048 map_2048::leftMap()
{
	ResetMergeFlag();
	for (int j = 0; j < m_n; j++)
	{
		for (int i = 0; i < m_n; i++)
		{
			if (m_map[i][j] != 0)
			{
				setNextPos(i, j, eDirection::LEFT);
			}
		}
	}
	return *this;
}

map_2048 map_2048::downMap()
{
	ResetMergeFlag();
	for (int i = m_n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (m_map[i][j] != 0)
			{
				setNextPos(i, j, eDirection::DOWN);
			}
		}
	}
	return *this;
}

void Start2048Games ( int n , map_2048 maps )
{
	// maps.ShowMap();

	if ( n == 5 )
	{
		g_answer = std::max( g_answer, maps.GetMaxValue() ) ;
		return;
	}

	map_2048 c_maps = maps;
	Start2048Games(n + 1, c_maps.rightMap());
	c_maps = maps;
	Start2048Games(n + 1, c_maps.leftMap());
	c_maps = maps;
	Start2048Games(n + 1, c_maps.downMap());
	c_maps = maps;
	Start2048Games(n + 1, c_maps.upMap());

	return ;
}

int main(void)
{
	int n;
	map_2048 maps;
	//FILE * inp = fopen("txt/test.txt", "r");
	//fscanf(inp, "%d", &n);
	scanf("%d", &n);
	maps.SetN(n);

	for ( int i = 0; i < n; i++ )
	{
		for (int j = 0; j < n; j++)
		{
			// fscanf(inp, "%d", &maps.m_map[i][j]);
			scanf("%d", &maps.m_map[i][j]);
		}
	}

 	Start2048Games(0, maps);
	printf("%d", g_answer);

	return 0;
}

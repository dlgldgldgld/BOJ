#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

typedef struct st_point
{
	int h;
	int line;

	st_point(int h, int line) : h(h), line(line)
	{

	}
};

std::vector<st_point> g_inputs;
int g_input_size = 0;
bool is_find = false;
bool b_select[301];
int g_answer = 2147483647;
int g_n;
int g_h;
int g_m;

// g_connect[H][FROM][TO] = H번째 Line에서 FROM 으로 TO로 갈수있다.
bool g_connect[31][11][11];

bool is_connect_self()
{
	bool is_conn = true;
	for (int i = 1; i <= g_n; i++)
	{
		int conn_i = i;
		for (int h = 1; h <= g_h; h++)
		{
			if ((conn_i + 1 <= g_n) &&
				true == g_connect[h][conn_i][conn_i + 1])
			{
				conn_i = conn_i + 1;
				continue;
			}

			if ((conn_i - 1 >= 1) &&
				true == g_connect[h][conn_i - 1][conn_i])
			{
				conn_i = conn_i - 1;
				continue;
			}
		}
		if (conn_i != i)
		{
			is_conn = false;
			break;
		}

	}

	return is_conn;
}

bool is_promise(int line_h, int n)
{

	if (n - 1 >= 1 && g_connect[line_h][n - 1][n] == true)
	{
		return false;
	}

	if (n + 1 <= g_n && g_connect[line_h][n][n + 1] == true)
	{
		return false;
	}

	if (n + 2 <= g_n && g_connect[line_h][n + 1][n + 2] == true)
	{
		return false;
	}

	return true;
}

static int sol_cnt = 0;

void solution(int sum, int idx)
{
	// Sum이 3이상이면 더이상 볼필요가 없음.
	if (sum > 3)
	{
		return;
	}

	// 답을 찾을상태인데 답보다 sum이 더크면 더이상 볼필요가 없음.
	if (is_find == true && sum >= g_answer)
	{
		return;
	}

	// 연결된 상태면 g_answer 보다 답을 찾은 것이담
	if (is_connect_self() == true)
	{
		g_answer = std::min(g_answer, sum);
		is_find = true;
		return;
	}

	// Sum이 3이상이면 더이상 볼필요가 없음.
	if (sum == 3)
	{
		return;
	}

	if (idx >= g_input_size)
	{
		return;
	}

	sol_cnt++;
	st_point pos = g_inputs.at(idx);
	if ( is_promise( pos.h, pos.line ) )
	{
		g_connect[pos.h][pos.line][pos.line + 1] = true;
		g_connect[pos.h][pos.line + 1][pos.line] = true;
		b_select[idx + 1] = true;
		solution(sum + 1, idx + 1);
		g_connect[pos.h][pos.line][pos.line + 1] = false;
		g_connect[pos.h][pos.line + 1][pos.line] = false;
		b_select[idx + 1] = false;
	}

	solution(sum, idx + 1);

	return;

}
int main(void)
{
	int line = 0, from_to = 0;
	//FILE * inp = fopen( "test.txt" , "r" );
	//fscanf( inp , "%d %d %d" , &g_n , &g_m , &g_h );
	scanf("%d %d %d", &g_n, &g_m, &g_h);
	for (int i = 0; i < g_m; i++)
	{
		//fscanf( inp , "%d %d" , &line , &from_to );
		scanf("%d %d", &line, &from_to);
		g_connect[line][from_to][from_to + 1] = true;
		g_connect[line][from_to + 1][from_to] = true;
	}

	for (int line = 1; line < g_n; line++)
	{
		for (int h = 1; h <= g_h; h++)
		{
			if (!is_promise(h, line))
			{
				continue;
			}
			g_inputs.push_back(st_point(h, line));
		}
	}

	g_input_size = static_cast<int>(g_inputs.size());
	solution(0, 0);

	if (g_answer > 3)
		g_answer = -1;

	//printf( "sol_cnt : %d\n" , sol_cnt );
	printf("%d", g_answer);
}
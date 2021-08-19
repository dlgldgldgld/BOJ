#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int g_r, g_c;
char g_inputs[21][21];
bool g_foot[21][21];
constexpr int UPPER_INDEX = 65;
int  g_list[30];
int g_answer = 0;

bool is_promising( int idx, char c_alphabet, int n_r, int n_c )
{
	if ( g_list[static_cast<int> (g_inputs[n_r][n_c]) - UPPER_INDEX] == 1)
	{
		return false;
	}
	// 맵 범위를 넘어선 곳이라면 지나가지 못한다.
	if (n_r < 0 || n_c < 0 || n_r >= g_r || n_c >= g_c)
	{
		return false;
	}

	// 이미 건너온 곳이라면 지나가지 못한다.
	if ( g_foot[n_r][n_c] == true )
	{
		return false;
	}

	return true;
}

void solution( int idx, int r_cnt, int c_cnt )
{
	if ( r_cnt < 0 || c_cnt < 0 || r_cnt >= g_r || c_cnt >= g_c )
	{
		return;
	}

	g_answer = std::max(idx, g_answer);

	for (int i = 0; i < 4; i++)
	{
		int n_r = r_cnt , n_c = c_cnt;
		if ( i == 0 )
			n_r = r_cnt + 1;
		else if ( i== 1 )
			n_r = r_cnt - 1;
		else if ( i== 2 )
			n_c = c_cnt + 1;
		else 
			n_c = c_cnt - 1;

		if ( !is_promising( idx, g_inputs[n_r][n_c], n_r, n_c ) )
		{
			continue;
		}

		g_foot[n_r][n_c] = true;
		g_list[ static_cast<int> (g_inputs[n_r][n_c]) - UPPER_INDEX] = 1;
		solution(idx + 1, n_r, n_c);
		g_foot[n_r][n_c] = false;
		g_list[static_cast<int> (g_inputs[n_r][n_c]) - UPPER_INDEX] = 0;

	}
	
	return;
}

int main(void)
{
	scanf("%d %d\n", &g_r, &g_c);
	for (int i = 0; i < g_r; i++)
	{
		for (int j = 0; j < g_c; j++)
		{
			scanf("%c", &g_inputs[i][j]);
			g_foot[i][j] = false;
		}
		char N_U_L_L;
		if ( i != g_r - 1 )
			scanf("%c", &N_U_L_L);
	}
	memset(g_list, 0, sizeof(int) * 30 ) ;
	g_foot[0][0] = true;
	g_list[static_cast<int> (g_inputs[0][0]) - UPPER_INDEX] = 1;
	solution(0, 0, 0);

	printf("%d", g_answer + 1);
}
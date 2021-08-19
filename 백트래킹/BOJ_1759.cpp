#include <cstdio>
#include <vector>
#include <limits.h>
#include <algorithm>

int  g_n, g_m;
char g_list[20];
std::vector<char> g_passlist;
//FILE * f_inp = fopen("txt/test.txt", "r");

bool isMo(char & a)
{
	if ( (a == 'a')
		|| (a == 'e')
		|| (a == 'i')
		|| (a == 'o')
		|| (a == 'u'))
	{
		return true;
	}

	return false;
}

void solution(int idx, int cn, int mo, int ja)
{
	if ( idx == g_n && mo >= 1 && ja >= 2)
	{
		for (int iCnt = 0; iCnt < g_n; iCnt++)
		{
			printf("%c", g_list[iCnt]);
		}
		printf("\n");
		return;
	}

	for (int iCnt = 0; iCnt < g_m; iCnt++)
	{
		if ( iCnt <= cn )
		{
			continue;
		}
		g_list[idx] = g_passlist.at(iCnt);
		bool ismo = isMo(g_list[idx]);
		ismo == true ? mo++ : ja++;
		solution(idx + 1, iCnt, mo, ja );
		ismo == true ? mo-- : ja--;
	}
	
	return;
}
int main(void)
{
	scanf("%d %d\n", &g_n, &g_m);
	int input_idx = 0;
	while( input_idx != g_m )
	{
		char inp;
		scanf("%c", &inp);
		if ( inp == ' ' ) 
			continue;

		g_passlist.push_back(inp);
		input_idx++;
	}

	std::sort(g_passlist.begin(), g_passlist.end());
	
	solution(0, -1, 0, 0);
}
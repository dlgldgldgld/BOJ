#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

inline int LowerAlphabetToint(char c)
{
	return static_cast<int>(c) - 97;
}

int g_n, g_m, g_lists_size;
int g_answer = 0;
int b_select;
int g_inputs[51];
std::vector<char> g_lists;
std::set<char> wordslist;
int GetMatchedLists(  )
{
	int correct_answer = 0;
	for (int i = 0; i < g_n; i++)
	{
		int c = g_inputs[i] & b_select;
		if ( c == g_inputs[i] )
		{
			correct_answer++;
		}
	}

	return correct_answer;
}
bool is_promising( char word )
{
	int c = b_select & ( 1 << LowerAlphabetToint(word) ) ;
	if ( c != 0 )
	{
		return false;
	}

	if ( wordslist.find(word) == wordslist.end() )
	{
		return false;
	}

	return true;
}

//FILE * out = fopen("aaa.txt", "w");
int col_cnt = 0;
void solution( int idx , int from_i )
{
	col_cnt++;
	if (idx == g_m || from_i == g_lists_size )
	{
		g_answer = std::max(g_answer, GetMatchedLists( ));
		return;
	}

	char currWord = g_lists.at(from_i);
	if ( is_promising( currWord ) )
	{
		b_select += ( 1 << LowerAlphabetToint(currWord) );
		solution(idx + 1, from_i + 1);
		b_select -= ( 1 << LowerAlphabetToint(currWord));
		solution(idx, from_i + 1);
	}
	return;
}

int main(void)
{
	//FILE * inp = fopen("test.txt", "r");
	char str[256];
	//fscanf(inp,"%d %d", &g_n, &g_m);
	scanf("%d %d", &g_n, &g_m);
	
	for (int i = 0; i < g_n; i++)
	{
		//fscanf(inp,"%s", str);
		scanf("%s", str);
		int str_len = strlen(str);
		g_inputs[i] = 0;
		std::set<char> word;
		for (int j = 0; j < str_len; j++)
		{
			word.insert(str[j]);
			
			wordslist.insert( str[j] );
		}

		for (auto j = word.begin(); j != word.end(); j++)
		{
			g_inputs[i] += (1 << LowerAlphabetToint(*j));
		}
	}

	for (auto i = wordslist.begin(); i != wordslist.end(); i++)
	{
		if (  *i == 'a' || *i == 'c' || *i == 'i' 
			|| *i == 'n' || *i == 't')
		{
			continue;
		}
		g_lists.push_back(*i);
	}
	g_lists_size = g_lists.size();
	// a c i n t
	// 0, 2, 8, 13, 19
	b_select += (1 << 0);
	b_select += (1 << 2);
	b_select += (1 << 8);
	b_select += (1 << 13);
	b_select += (1 << 19);

	if ( g_m < 5 )
	{

	}
	else
	{
		solution(5, 0);
	}
	//printf("%d\n", col_cnt);
	printf("%d", g_answer);
	
	return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>
#pragma warning (disable : 4996)


int n, m;

void PrintAnswer( int idx, std::vector<int> & answer )
{
	if ( idx == m )
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", answer[i]);
		}
		printf("\n");
		return ;
	}

	for ( int i = 1; i <= n; i++ )
	{
		bool isPass = false;
		for (int j = 0; j < idx; j++)
		{
			if (  answer.at(j) == i )
			{
				isPass = true; 
				break;
			}
		}

		if (isPass == true)
		{
			continue;
		}

		answer.push_back(i);
		PrintAnswer(idx + 1, answer);
		answer.pop_back();
	}
	return;
}

int main(void)
{
	std::vector<int> answer;
	answer.reserve(10);
	scanf("%d %d", &n, &m);

	PrintAnswer(0, answer);

	return 0;
}
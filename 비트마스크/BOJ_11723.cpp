#include <cstdio>
#include <cstring>

int main(void)
{
	int set = 0;
	int N, x;
	char oper[256];
	//FILE * inp = fopen("test.txt", "r");
	//fscanf(inp, "%d", &N);
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		//fscanf(inp,"%s %d", oper, &x);
		scanf("%s %d", oper, &x);
		x -= 1;
		
		if ( strcmp(oper, "add") == 0 )
		{
			set = set | (1 << x);
		}
		else if (strcmp(oper, "remove") == 0)
		{
			set = set & ~ (1 << x);
		}
		else if (strcmp(oper, "check") == 0)
		{
			if ( ( set & ( 1 << x ) ) == ( 1 << x ) )
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if (strcmp(oper, "toggle") == 0)
		{
			set = set ^ ( 1 << x );
		}
		else if (strcmp(oper, "all") == 0)
		{
			set = 1048575;
		}
		else if (strcmp(oper, "empty") == 0)
		{
			set = 0;
		}
	}

	return 0;
}

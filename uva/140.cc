#include <cstdio>
#include <cstring>
bool graph[8][8],visited[8][8];
int ans[8];
bool input()
{
	char str[90];
	int new_point,neighbour_point;
	scanf("%s",str);
	if (str[0]=='#') return 0;
	int len=strlen(str);
	enum state{INIT,NEW_P,MH,NEIGH_P,FH,FINISH};
	state s=INIT;
	while (s!=FINISH)
	{
		switch(s)
		{
			case INIT:
		}
	}
}
void dfs(int cur)
{
	if ()
}
int main()
{

	return 0;
}


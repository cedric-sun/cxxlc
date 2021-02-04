#include <cstdio>
#include <cstring>
const int l=4450;
int n,m,ans,path[l],cnt;
bool graph[l][l],searched[l][l];

void dfs(int cur,int prev)
{
	if (path[cur])
	{
		searched[cur][prev]=true;
		int temp=cnt-path[cur]+1;
		if (temp>ans) ans=temp;
		return;
	}
	path[cur]=++cnt;
	for (int i = 1; i <=n; i++)
	{
		if (graph[cur][i]&&i!=prev&&!searched[cur][i])
			dfs(i,cur);
	}
	path[cur]=0;
	cnt--;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(graph,0,sizeof graph);
		memset(path,0,sizeof path);
		memset(searched,0,sizeof searched);
		scanf("%d %d",&n,&m);
		for (int i=0;i<m;i++)
		{
			int p1,p2;
			scanf("%d %d",&p1,&p2);
			graph[p1][p2]=true;
			graph[p2][p1]=true;
		}

		cnt=0;ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}


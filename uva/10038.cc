#include <cstdio>
#include <cstring>
#include <cstdlib>
const char ans[][10]={"Not jolly","Jolly"};
int n,a[3005],visited[3005];
int judge()
{
	for (int i = 1; i < n; i++)
	{
		int temp=abs(a[i]-a[i-1]);
		if (!temp||temp>n-1||visited[temp]) return 0;
		visited[temp]=1;
	}
	return 1;
}
int main()
{
	while (~scanf("%d",&n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d",a+i);
		memset(visited,0,sizeof visited);
		printf("%s\n",ans[judge()]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
const int l=21;

int target,ans[l],path_length,cnt;
bool graph[l][l],visited[l];
int father[l];

int finds(int a)
{
    if (father[a]!=a) father[a]=finds(father[a]);
    return father[a];
}

void output()
{
    for (int i = 0; i < path_length; i++)
    {
        if (i) putchar(' ');
        printf("%d",ans[i]);
    }
    putchar('\n');
}
void dfs(int cur)
{
    if (cur==target)
    {
        output();
        cnt++;
        return;
    }

    for (int i = 1; i <l; i++)
    {
        if (graph[cur][i]&&!visited[i]&&finds(i)==finds(target))
        {
            visited[i]=true;
            ans[path_length++]=i;
            dfs(i);
            path_length--;
            visited[i]=false;
        }
    }
}
int main()
{
    int cases=1;
    while (scanf("%d",&target)!=EOF)
    {
        int i,j;
        memset(graph,0,sizeof graph);
        for (int i=1; i<l; i++) father[i]=i;
        while (scanf("%d %d",&i,&j)&&i)
        {
            graph[i][j]=graph[j][i]=1;
            i=finds(i),j=finds(j);
            father[i]=j;
        }

        printf("CASE %d:\n",cases++);
        path_length=1;
        ans[0]=1;
        cnt=0;
        memset(visited,0,sizeof visited);
        visited[1]=true;

        dfs(1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,target);

    }
    return 0;
}


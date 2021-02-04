#include <cstdio>
#include <set>
//#include <unordered_set>
using namespace std;

int g[5][5],tmp;
set<int> c;
//unordered_set<int> c;
const int di[]={1,0,-1,0},dj[]={0,1,0,-1};

void dfs(int i,int j,int d)
{
    tmp=tmp*10+g[i][j];
    if (d>=5)
    {
        if (!c.count(tmp)) c.insert(tmp);
        tmp/=10;
        return;
    }

    for (int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if (ni>=0 && ni<5 && nj>=0 && nj<5)
            dfs(ni,nj,d+1);
    }
    tmp/=10;
}
int main()
{
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            scanf("%d",&g[i][j]);
    tmp=0;
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            dfs(i,j,0);
    printf("%d\n",int(c.size()));
    return 0;
}

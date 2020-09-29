#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    bool isnum;
    int value,id;
};
struct coor
{
    int r,c;
    coor(int rr,int cc):r(rr),c(cc){};
};
vector<vector<node> > G;
vector<vector<coor> >depG;
vector<coor> avail;

int dfs(int r,int c)
{
    if (G[r][c].isnum)
        return G[r][c].value;

    int sum=0;
    for (vector<coor>::iterator it= depG[G[r][c].id].begin(); it!=depG[G[r][c].id].end(); it++)
        sum+=dfs((*it).r,(*it).c);

    G[r][c].isnum=1;
    return G[r][c].value=sum;
}

void read(int r,int c)
{
    char str[100];
    scanf("%s",str);
    if (str[0]=='=')
    {
        G[r][c].isnum=0;
        G[r][c].id=depG.size();
        avail.push_back(coor(r,c));
        vector<coor> temp;
        int len=strlen(str);
        int rr=0,cc=0;
        for (int p=1; p<=len; p++)
        {
            if (isalpha(str[p]))
                cc=cc*26+str[p]-'A'+1;
            else if (isdigit(str[p]))
                rr=rr*10+str[p]-'0';
            else
            {
                temp.push_back(coor(rr,cc));
                rr=cc=0;
            }
        }

        depG.push_back(temp);
    }
    else
    {
        G[r][c].isnum=1;
        G[r][c].value=strtol(str,NULL,10);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d %d",&m,&n);
        G.clear();depG.clear();avail.clear();
        G.resize(n+1);
        for (int i=1; i<=n; i++) G[i].resize(m+1);
        for (int r=1; r<=n; r++)
            for (int c=1; c<=m; c++)
                read(r,c);

        int len=avail.size();
        for (int i=0; i<len; i++)
            if (!G[avail[i].r][avail[i].c].isnum)
                dfs(avail[i].r,avail[i].c);

        for (int r=1; r<=n; r++)
        {
            for (int c=1; c<=m; c++)
            {
                if (c-1) putchar(' ');
                printf("%d",G[r][c].value);
            }
            putchar('\n');
        }
    }
    return 0;
}

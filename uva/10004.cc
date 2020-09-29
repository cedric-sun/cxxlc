#include <cstdio>
#include <vector>
using namespace std;

struct node
{
    int no;
    bool vis,color;
    vector<int> l;
};

vector<node> g;

void dfs(int i,bool col)
{
    g[i].color=col;
    g[i].vis=true;
    for (vector<int>::iterator it = g[i].l.begin(); it!=g[i].l.end(); it++)
        if (!(g[*it].vis))
            dfs(g[*it].no,!col);
}

bool judge(int n)
{
    for (int i=0; i<n; i++)
    {
        for (vector<int>::iterator it = g[i].l.begin(); it!=g[i].l.end(); it++)
            if (g[*it].color==g[i].color)
                return false;
    }
    return true;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        g.clear();
        g.resize(n);
        for (int i=0; i<n; i++)
        {
            g[i].no=i;
            g[i].vis=false;
        }
        int e;
        scanf("%d",&e);
        for(int i=0; i<e; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            g[a].l.push_back(b);
            g[b].l.push_back(a);
        }

        dfs(0,0);

        if (judge(n))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}

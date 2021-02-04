#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
typedef unsigned char uc;
const int N=0x100;
int n,m;
int mat[10][20];
vector<vector<uc> > g;  //邻接表用来存图
bool vis[N];
char e[N][N];           //e[i][j]表示从i节点到j节点所需的指令
string path[N];

bool bfs()
{
    uc s=(1<<n)-1;
    queue<uc> q;
    path[s].clear();
    vis[s]=1;
    q.push(s);
    while (!q.empty())
    {
        uc cur=q.front();
        //printf("current top:%u\n",(ui)cur);
        q.pop();
        for (vector<uc>::iterator it=g[cur].begin();it!=g[cur].end();++it)
        {
            if (!vis[*it])
            {
                //printf("\t visiting:%u\n",(ui)*it);
                vis[*it]=1;
                path[*it]=path[cur]+e[cur][*it];
                //printf("\t path: %s\n",path[(ui)*it].c_str());
                if (*it==1)
                    return 1;
                q.push(*it);
            }
            //else
            //    printf("\t fail to visit:%u\n",(ui)*it);
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d",&mat[i][j]);
    g.clear();g.resize(1<<n);
    memset(vis,0,sizeof vis);
    for (int i=(1<<n)-1; i>0; i--)  //对于n种状态，初始节点是所有状态的可能性都存在的集合
        for (int j=0; j<m; j++)     //所以用n个全为1的二进制位来表示
        {
            uc tmp=0;
            for (int k=0; k<n; k++)
                if ((i>>k)&1) tmp|=(1<<mat[k][j]);
            g[i].push_back(tmp);
            e[i][tmp]=j>9?j-10+'a':j+'0';   //题目说结果用16进制输出，因为指令编号最多可以有16种
        }

    /*
    for (int i=0;i<(1<<n);i++){
            printf("g[%d]:",i);
        for (vector<uc>::iterator it=g[i].begin();it!=g[i].end();++it)
        printf(" %u",(ui)*it);
        putchar('\n');
    }
    */


    if (bfs())
    printf("%s\n",path[1].c_str());
    else
        puts("*");
    return 0;
}

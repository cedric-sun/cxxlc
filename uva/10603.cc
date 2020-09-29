#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct State_node
{
    int vol[3],already_moved_vol;
    bool operator < (const State_node &rhs) const
    {
        return already_moved_vol >rhs.already_moved_vol;
    }
};

const int l=205;
int capacity[3],ans[l],a,b,c,d;
bool vis[l][l];

void update(const State_node &u)
{
    for (int i = 0; i < 3; i++)
    {
        int temp=u.vol[i];
        if (ans[temp]<0||u.already_moved_vol<ans[temp]) ans[temp]=u.already_moved_vol;
    }
}
void BFS()
{
    capacity[0]=a,capacity[1]=b,capacity[2]=c;
    memset(vis,0,sizeof vis);
    memset(ans,-1,sizeof ans);
    priority_queue<State_node> q;
    State_node start;
    start.already_moved_vol=0;
    start.vol[0]=start.vol[1]=0,start.vol[2]=c;

    q.push(start);
    vis[0][0]=1;

    while (!q.empty())
    {
        State_node u=q.top();
        q.pop();
        update(u);
        if (ans[d]>=0) break;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i!=j)
                {
                    if (u.vol[i]==0||u.vol[j]==capacity[j]) continue;
                    int amount=min(capacity[j],u.vol[i]+u.vol[j])-u.vol[j];
                    State_node u2;
                    memcpy(&u2,&u,sizeof u);
                    u2.already_moved_vol=u.already_moved_vol+amount;
                    u2.vol[i]-=amount;
                    u2.vol[j]+=amount;
                    if (!vis[u2.vol[0]][u2.vol[1]])
                    {
                        vis[u2.vol[0]][u2.vol[1]]=1;
                        q.push(u2);
                    }
                }
            }
        }
    }

    for (; d>=0; d--)
    {
        if (ans[d]>=0)
        {
            printf("%d %d\n",ans[d],d);
            return;
        }
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        BFS();
    }
    return 0;
}


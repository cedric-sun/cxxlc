#include <cstdio>
#include <queue>
using std::queue;

int card[30],ans[30];
queue<int> q;

int main()
{
    int n,k,m,cur,t,lim;
    while (scanf("%d %d",&n,&k),n)
    {
        for (int i=1;i<=n;i++) {card[i]=40;q.push(i);}
        m=1,t=0,lim=1;
        while (!q.empty())
        {
            cur=q.front();
            q.pop();
            if (card[cur]<lim) //没取完盒子里的钱，因为取够了40
            {
                lim-=card[cur];
                card[cur]=0;
            }
            else //取完了盒子里的钱
            {
                card[cur]-=lim;
                if (++m>k) m=1;
                lim=m;
            }

            if (card[cur])
                q.push(cur);
            else
                ans[t++]=cur;
        }

        for (int i=0;i<t;i++)
            printf("%3d",ans[i]);
        putchar('\n');
    }
    return 0;

}

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct gas_station
{
    int d,o;
    bool operator < (const gas_station &ref) const {return d>ref.d;}
    gas_station(int _d=0,int _o=0):d(_d),o(_o){}
}gas[10005];

int n,l,p;

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;i++) scanf("%d %d",&gas[i].d,&gas[i].o);
        sort(gas,gas+n);
        scanf("%d %d",&l,&p);
        priority_queue<int> q;
        int prev=0,cnt=0,ok=1;
        while (1)
        {
            int i=upper_bound(gas,gas+n,gas_station(l-p,0))-gas;
            for (int j=prev;j<i;j++) q.push(gas[j].o);
            prev=i;
            l-=p;
            if (l<=0) break;
            if (q.empty()) {ok=0;break;}
            p=q.top();q.pop();
            cnt++;
        }
        if (ok) printf("%d\n",cnt);
        else printf("-1\n");
    }
    return 0;
}

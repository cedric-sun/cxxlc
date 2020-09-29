#include <cstdio>
#include <algorithm>
using namespace std;

int r,n;
int t[1005];

int main()
{
    while (scanf("%d %d",&r,&n),~r)
    {
        for (int i=0;i<n;i++)
            scanf("%d",t+i);
        sort(t,t+n);
        int i=0,ans=0;
        while (i<n)
        {
            ans++;
            int pos=upper_bound(t,t+n,t[i]+r)-t-1;
            i=upper_bound(t,t+n,t[pos]+r)-t;
        }
        printf("%d\n",ans);
    }
    return 0;
}

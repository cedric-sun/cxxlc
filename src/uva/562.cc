#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int N=100+5,M=N*500;

int sum,a[N];
set<int> dp;

void zoknap(int w)
{
    for (int j=sum;j>=w;j--)
        if (dp.count(j-w)) dp.insert(j);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        sum=0;
        for (int i=0;i<n;i++) {scanf("%d",a+i);sum+=a[i];}
        dp.clear();dp.insert(0);

        for (int i=0;i<n;i++) zoknap(a[i]);

        //for (set<int>::iterator it=dp.begin();it!=dp.end();++it) printf("%d ",*it);

        set<int>::iterator it=--upper_bound(dp.begin(),dp.end(),sum>>1);

        printf("%d\n",sum-2*(*it));
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        v.clear();
        for (int i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            int b=sqrt(a)+1;
            for (int j=2; j<=b && a>1; j&1?j+=2:j++)
                while (!(a%j))
                {
                    v.push_back(j);
                    a/=j;
                }
            if (a!=1)
                v.push_back(a);
        }
        if (v.size()<2) puts("-1");
        else
        {
            sort(v.begin(),v.end());
            printf("%lld\n",v[0]*v[1]);
        }
    }
    return 0;
}

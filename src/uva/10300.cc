#include <cstdio>
int main()
{
    int T,n;
    long long a,b,c,ans;

    scanf("%d",&T);
    while (T--)
    {
        ans=0;
        scanf("%d",&n);
        while (n--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            if (b)
            ans+=a*c;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

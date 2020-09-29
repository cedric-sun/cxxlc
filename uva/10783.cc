#include <cstdio>
int main()
{
    int T,a,b;
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);
        if (!(a&1)) a++;
        if (!(b&1)) b--;
        printf("Case %d: %d\n",i,((b-a)/2+1)*(a+b)/2);
    }
    return 0;
}

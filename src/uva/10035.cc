#include <cstdio>
int main()
{
    long long a,b;
    while (scanf("%lld %lld",&a,&b)&&(a||b))
    {
        int ans=0,carry=0;
        while (a||b)
        {
            if (a%10+b%10+carry>9)
            {
                ans++;
                carry=1;
            }
            else
                carry=0;
            a/=10;
            b/=10;
        }
        if (ans>1)
            printf("%d carry operations.\n",ans);
        else if (ans==1)
            printf("%d carry operation.\n",ans);
        else
        printf("No carry operation.\n");
    }
    return 0;
}

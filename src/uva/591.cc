#include <cstdio>
#include <algorithm>
int a[55];
int main()
{
    int n,cnt=1;
    while (scanf("%d",&n)&&n)
    {
        int sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        int aver=sum/n;
        int ans=0;
        for (int i=0;i<n;i++)
            ans+=abs(aver-a[i]);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",cnt++,ans/2);
    }
    return 0;
}

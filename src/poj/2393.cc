/*#include<iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, s, minc = 9999;
    scanf("%d %d",&n, &s);
    long long sum = 0;
    while(n --){
        int c, y;
        scanf("%d %d",&c, &y);
        if(c > minc + s)  c = minc + s;  //  维护最优的代价。
        minc = c;
        sum += c * y;
    }
    printf("%lld\n", sum);
    return 0;
}
*/
#include <cstdio>
#include <cstring>

int c[10005],y[10005];
bool vis[10005];
int main()
{
    int n,s;
    while (~scanf("%d %d",&n,&s))
    {
        for (int i=0; i<n; i++)
            scanf("%d %d",c+i,y+i);
        long long ans=0;
        memset(vis,0,sizeof vis);
        for (int i=0; i<n; i++)
        {
            if (vis[i]) continue;
            vis[i]=1;
            ans+=c[i]*y[i];
            int tmp;
            for (int j=i+1; (tmp=c[i]*y[j]+s*y[j]*(j-i))<c[j]*y[j] && j<n; j++)
            {
                ans+=tmp;
                vis[j]=1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

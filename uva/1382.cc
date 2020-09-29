#include <cstdio>
#include <algorithm>
using namespace std;

const int N=100+5;

struct point
{
    int x,y;
    bool operator<(const point &ref) const {return  x<ref.x;}
}p[N];

int n;
int y[N],on[N],on2[N],left[N];
//y[]:      存储每个点的纵坐标，排序去重之后以便枚举每一条横线
//on[i]:    在第i条竖线上，并且纵坐标在(ymin,ymax)区间上的点的个数
//on2[i]:   在第i条竖线上，并且纵坐标[ymin,ymax]区间上的点的个数
//left[i]:  在第i条竖线左边，且在y=ymin和y=ymax两条横线上的点的个数

int solve()
{
    sort(p,p+n);sort(y,y+n);
    int m=unique(y,y+n)-y;
    if (m<=2) return n;//只有2条横线，画一个矩形可以使所有点均落在该矩形上

    int ans=0;
    for (int a=0; a<m; a++)//枚举每一对横线
    {
        for (int b=a+1; b<m; b++)
        {
            int ymin=y[a],ymax=y[b];//接下来的计算以确定的上下横线区间作为前提
            int k=0;
            for (int i=0;i<n;i++)//枚举每一个点
            {
                if (i==0 || p[i].x != p[i-1].x)//找到一个新竖线
                {
                    k++;
                    on[k]=on2[k]=0;
                    left[k]=left[k-1]+on2[k-1]-on[k-1];
                }

                if (p[i].y>ymin && p[i].y<ymax) on[k]++;
                if (p[i].y>=ymin && p[i].y<=ymax) on2[k]++;
            }

            if (k<=2) return n;//只有2条竖线，画一个矩形可以使所有点均落在该矩形上

            int M=0;
            //设矩形左右边界分别为第j和i根竖线（上下边界是ymax,ymin)
            //则矩形边上的点的个数为left[i]-left[j]+on2[i]+on[j]
            //所以枚举右边界i的同时，维护最大的on[j]-left[j]作为左边界j
            for (int i=1;i<=k;i++)
            {
                ans=max(ans,left[i]+on2[i]+M);
                M=max(M,on[i]-left[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int cnt=1;
    while (scanf("%d",&n),n)
    {
        for (int i=0; i<n; i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            y[i]=p[i].y;
        }
        printf("Case %d: %d\n",cnt++,solve());
    }
    return 0;
}

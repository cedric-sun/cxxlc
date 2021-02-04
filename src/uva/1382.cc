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
//y[]:      �洢ÿ����������꣬����ȥ��֮���Ա�ö��ÿһ������
//on[i]:    �ڵ�i�������ϣ�������������(ymin,ymax)�����ϵĵ�ĸ���
//on2[i]:   �ڵ�i�������ϣ�����������[ymin,ymax]�����ϵĵ�ĸ���
//left[i]:  �ڵ�i��������ߣ�����y=ymin��y=ymax���������ϵĵ�ĸ���

int solve()
{
    sort(p,p+n);sort(y,y+n);
    int m=unique(y,y+n)-y;
    if (m<=2) return n;//ֻ��2�����ߣ���һ�����ο���ʹ���е�����ڸþ�����

    int ans=0;
    for (int a=0; a<m; a++)//ö��ÿһ�Ժ���
    {
        for (int b=a+1; b<m; b++)
        {
            int ymin=y[a],ymax=y[b];//�������ļ�����ȷ�������º���������Ϊǰ��
            int k=0;
            for (int i=0;i<n;i++)//ö��ÿһ����
            {
                if (i==0 || p[i].x != p[i-1].x)//�ҵ�һ��������
                {
                    k++;
                    on[k]=on2[k]=0;
                    left[k]=left[k-1]+on2[k-1]-on[k-1];
                }

                if (p[i].y>ymin && p[i].y<ymax) on[k]++;
                if (p[i].y>=ymin && p[i].y<=ymax) on2[k]++;
            }

            if (k<=2) return n;//ֻ��2�����ߣ���һ�����ο���ʹ���е�����ڸþ�����

            int M=0;
            //��������ұ߽�ֱ�Ϊ��j��i�����ߣ����±߽���ymax,ymin)
            //����α��ϵĵ�ĸ���Ϊleft[i]-left[j]+on2[i]+on[j]
            //����ö���ұ߽�i��ͬʱ��ά������on[j]-left[j]��Ϊ��߽�j
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

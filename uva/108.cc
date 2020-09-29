#include <cstdio>
#include <algorithm>
using std::max;

int n;
int M[105][105];

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                M[i][j]=M[i-1][j]+M[i][j-1]-M[i-1][j-1]+tmp;
            }
        }
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%d ",M[i][j]);
            putchar('\n');
        }
        */
        int maxS=0;

        for (int i1=1;i1<=n;i1++)
            for (int j1=1;j1<=n;j1++)
                for (int i2=i1;i2<=n;i2++)
                    for (int j2=j1;j2<=n;j2++)
                        maxS=max(maxS,M[i2][j2]-M[i2][j1-1]-M[i1-1][j2]+M[i1-1][j1-1]);

        printf("%d\n",maxS);
    }
    return 0;
}

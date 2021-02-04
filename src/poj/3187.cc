#include <cstdio>
#include <algorithm>
using namespace std;

int n,sum;
int pascal[11][11];

void init()
{
    for (int i=1;i<=10;i++)
    {
        pascal[i][1]=pascal[i][i]=1;
        for (int j=2;j<i;j++)
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
    }
}
/*
void printpascal()
{
    for (int i=1;i<=10;i++)
    {
        for (int j=1;j<=i;j++)
            printf("%d ",pascal[i][j]);
        putchar('\n');
    }
}
*/
void printans(int *ans)
{
    for (int i=1;i<=n;i++)
    {
        if (i!=1) putchar(' ');
        printf("%d",ans[i]);
    }
    putchar('\n');
}
void calc()
{
    int tmp[11];
    for (int i=1;i<=n;i++)
        tmp[i]=i;
    do
    {
        int tmpsum=0;
        for (int i=1;i<=n;i++)
            tmpsum+=tmp[i]*pascal[n][i];
        if (tmpsum==sum)
        {
            printans(tmp);
            break;
        }
    }while (next_permutation(tmp+1,tmp+n+1));
}
int main()
{
    init();
    //printpascal();
    scanf("%d %d",&n,&sum);
    calc();
    return 0;
}

#include <cstdio>
#include <set>
#include <cstring>
#include <string>
using std::set;
using std::string;
char str[105];
int num[2][55];
int N,n;
set<string> lib;

bool judge()
{
    int i,j,k,t;
    for (i=j=k=0;i<N;i++)
    {
        str[i]=num[k][j++]+1;
        if (j>=n) {j=0;k++;}
    }
    if (lib.count(str)) return 0;

    for (i=j=0,k=t=1;i<N;i++)
    {
        str[i]=num[k][j]+1;
        j+=t;
        if (j>=n) {t=-1;k--;j=n-1;}
    }
    if (lib.count(str)) return 0;

    for (i=k=0,j=n-1;i<N;i++)
    {
        str[i]=num[k][j--]+1;
        if (j<0) {j=n-1;k++;}
    }
    if (lib.count(str)) return 0;

    for (i=0,j=n-1,k=1,t=-1;i<N;i++)
    {
        str[i]=num[k][j]+1;
        j+=t;
        if (j<0) {t=1;k--;j++;}
    }
    if (lib.count(str)) return 0;

    lib.insert(str);
    return 1;
}

int main()
{
    while (scanf("%d",&n),n)
    {
        int a,b;
        char c;
        N=n<<1;
        lib.clear();
        memset(num,0,sizeof num);
        bool flag=0;
        for (int i=0;i<N;i++)
        {
            scanf("%d %d %c",&a,&b,&c);
            if (flag) continue;
            int t=(c=='+')?1:-1;
            num[0][a-1]+=t;
            num[1][b-1]+=t;

            if (!judge())
            {
                printf("Player %d wins on move %d\n",((i+1)&1)+1,i+1);
                flag=1;
            }
        }

        if (!flag)
            printf("Draw\n");
    }
    return 0;
}

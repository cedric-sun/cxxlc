#include <cstdio>
#include <set>
#include <cctype>
using std::set;

int f[30];

int uf(int x)
{
    if (f[x]!=x) f[x]=uf(f[x]);
    return f[x];
}

int main()
{
    int T;
    set<int> t;
    scanf("%d",&T);getchar();getchar();
    for (int i=0;i<T;i++)
    {
        int n=getchar()-'A';getchar();
        for (int j=0;j<=n;j++) f[j]=j;
        char c1,c2;
        while (isalpha(c1=getchar()))
        {
            c2=getchar();
            int a=uf(c1-'A'),b=uf(c2-'A');
            f[a]=b;
            getchar();
        }
        t.clear();
        for (int j=0;j<=n;j++) t.insert(uf(j));
        if (i) putchar('\n');
        printf("%d\n",t.size());
    }
    return 0;
}

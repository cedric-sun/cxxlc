#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=5700;

struct tur
{
    int w,s;
    bool operator < (const tur &ref) const {return s<ref.s;}
}T[N];

int dp[N][N];//ǰiֻ�ڹ���ɸ߶�Ϊj�Ķѵ�������

int main()
{
    int w,s,n=0;
    while (~scanf("%d %d",&w,&s))
    {
        ++n;
        T[n].w=w;T[n].s=s;
    }

    sort(tur+1,tur+n+1);

    printf("%d\n",ans);
    return 0;
}

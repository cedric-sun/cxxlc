#include <cstdio>
#include <algorithm>
using namespace std;

struct boulder
{
    int pos;
    bool sinkable,sinked;
    bool operator < (const boulder &ref) const
    {
        return pos<ref.pos;
    }
} b[105];

int n,d;

int main()
{
    int T;
    scanf("%d",&T);
    for (int k=0; k<T; k++)
    {
        scanf("%d %d",&n,&d);
        for (int i=0; i<n; i++)
        {
            char type;
            int pos;
            scanf("%c-%d",&type,&pos);
            b[i].pos=pos;
            b[i].sinkable=(type=='B'?0:1);
            b[i].sinked=0;
        }

        sort(b,b+n);

        int cur_pos,cur_index,max_leap;
        cur_index=0;
        cur_pos=max_leap=b[0].pos;
        if (b[0].sinkable) b[0].sinked=1;

        while (d-cur_pos>=max_leap)
        {

        }


    }
}

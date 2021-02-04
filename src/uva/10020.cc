#include <cstdio>
#include <algorithm>
using namespace std;

const int N=100000+5;
const int NEG_INF=0x80000000;

struct _seg
{
    int l,r;
    bool operator < (const _seg &ref) const
    {
        if (l==ref.l) return r<ref.r;
        return l<ref.l;
    }
}seg[N],ans_seg[N];

int main()
{
    int T;
    scanf("%d",&T);
    for (int SAKUYA=0;SAKUYA<T;SAKUYA++)
    {
        int M;
        scanf("%d",&M);
        int l,r,seg_size=0;
        while (scanf("%d %d",&l,&r),l||r)
        {
            if (l>M || r<0) continue;
            seg[seg_size].l=l;
            seg[seg_size].r=r;
            ++seg_size;
        }

        sort(seg,seg+seg_size);
        seg[seg_size].l=0xDEADBEEF;

        int ans_cnt=0;
        int cur_pos=0;
        while (cur_pos<M)
        {
            int its_L,max_R=NEG_INF;
            for (int i=0;i<seg_size;++i)
            {
                if (seg[i].l>cur_pos) break;
                //Only check the last one when many seg[i] have the same left
                if (seg[i].l<=cur_pos && seg[i].r>cur_pos && seg[i].l!=seg[i+1].l && max_R<seg[i].r)
                {
                    its_L=seg[i].l;
                    max_R=seg[i].r;
                }
            }
            if (max_R==NEG_INF) {ans_cnt=0;break;}
            cur_pos=max_R;
            ans_seg[ans_cnt].l=its_L;
            ans_seg[ans_cnt].r=max_R;
            ++ans_cnt;
        }

        if (SAKUYA) putchar('\n');
        printf("%d\n",ans_cnt);
        for (int i=0;i<ans_cnt;i++)
            printf("%d %d\n",ans_seg[i].l,ans_seg[i].r);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct point
{
    int x,y;
    point(const int &_x,const int &_y):x(_x),y(_y){}
};

struct line_segment
{
    point p1,p2;
    line_segment(const point &_p1,const point &_p2):p1(_p1),p2(_p2){}
};

struct _vector
{
    //st:(0,0)  ed:(x,y)
    int x,y;
    _vector(const point &st,const point &ed):x(ed.x-st.x),y(ed.y-st.y){}
};

int vector_product(const _vector &v1,const _vector &v2)
{
    int tmp=v1.x*v2.y-v2.x*v1.y;
    if (tmp>0) return 1;
    else if (tmp<0) return -1;
    else return 0;
}

bool fast_exclusion_test(const line_segment &l1,const line_segment &l2)
{
    return
    min(l1.p1.x,l1.p2.x)<=max(l2.p1.x,l2.p2.x) &&
    min(l2.p1.x,l2.p2.x)<=max(l1.p1.x,l1.p2.x) &&
    min(l1.p1.y,l1.p2.y)<=max(l2.p1.y,l2.p2.y) &&
    min(l2.p1.y,l2.p2.y)<=max(l1.p1.y,l1.p2.y);
}

bool cross_test(const line_segment &l1,const line_segment &l2)
{
    return
    vector_product(_vector(l2.p1,l2.p2),_vector(l2.p1,l1.p1))*vector_product(_vector(l2.p1,l2.p2),_vector(l2.p1,l1.p2))<=0
    &&
    vector_product(_vector(l1.p1,l1.p2),_vector(l1.p1,l2.p2))*vector_product(_vector(l1.p1,l1.p2),_vector(l1.p1,l2.p1))<=0;
}

bool isolated[105];
vector<line_segment> cowabunga;

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        cowabunga.clear();
        memset(isolated,1,sizeof isolated);

        int m;
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            int p1x,p1y,p2x,p2y;
            scanf("%d %d %d %d",&p1x,&p1y,&p2x,&p2y);
            cowabunga.push_back(line_segment( point(p1x,p1y) , point(p2x,p2y) ));
        }

        for (int i=0;i<m-1;i++)
        {
            for (int j=i+1;j<m;j++)
            {
                if (fast_exclusion_test(cowabunga[i],cowabunga[j]) && cross_test(cowabunga[i],cowabunga[j]))
                    isolated[i]=isolated[j]=0;
            }
        }

        int ans=0;
        for (int i=0;i<m;i++) if (isolated[i]) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}

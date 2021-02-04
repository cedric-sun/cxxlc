#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
    double x,y;
    point(const double &_x,const double &_y):x(_x),y(_y){}
};

struct line_segment
{
    point p1,p2;
    line_segment(const point &_p1,const point &_p2):p1(_p1),p2(_p2){}
};

struct _vector
{
    //st:(0,0)  ed:(x,y)
    double x,y;
    _vector(const point &st,const point &ed):x(ed.x-st.x),y(ed.y-st.y){}
};

double vector_product(const _vector &v1,const _vector &v2)
{
    return v1.x*v2.y-v2.x*v1.y;
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

vector<line_segment> cowabunga;
vector<int> ans;

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        cowabunga.clear();
        ans.clear();
        for (int i=0;i<n;i++)
        {
            double p1x,p1y,p2x,p2y;
            scanf("%lf %lf %lf %lf",&p1x,&p1y,&p2x,&p2y);
            cowabunga.push_back(line_segment(point(p1x,p1y),point(p2x,p2y)));
        }

        for (int i=0;i<n;i++)//the last one must be uncovered, so i<n, not i<n-1
        {
            bool covered=0;
            for (int j=i+1;j<n;j++)
            {
                if (fast_exclusion_test(cowabunga[i],cowabunga[j]) && cross_test(cowabunga[i],cowabunga[j]))
                {
                    covered=1;
                    break;
                }
            }

            if (!covered) ans.push_back(i+1);
        }

        printf("Top sticks:");
        for (int i=0;i<ans.size();i++)
        {
            if (i) putchar(',');
            printf(" %d",ans[i]);
        }
        puts(".");
    }
    return 0;
}


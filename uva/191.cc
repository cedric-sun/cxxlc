#include <cstdio>
#include <algorithm>
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

bool point_in_rec(const point &p,const point &left_top,const point &right_bottom)
{
    return (p.x>=left_top.x) && (p.x<=right_bottom.x) && (p.y<=left_top.y) && (p.y>=right_bottom.y);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int sx,sy,ex,ey;//start/end x/y
        int p1x,p1y,p2x,p2y;

        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        point st(sx,sy),ed(ex,ey);//st ed to form the line

        scanf("%d %d %d %d",&p1x,&p1y,&p2x,&p2y);
        point   p0(min(p1x,p2x),max(p1y,p2y)),  //p0 is the left top
                p1(max(p1x,p2x),max(p1y,p2y)),  //p1 is the right top
                p2(max(p1x,p2x),min(p1y,p2y)),  //p2 is the right bottom
                p3(min(p1x,p2x),min(p1y,p2y));  //p3 is the left bottom

        line_segment jerk_line(st,ed);
        line_segment l[4]={line_segment(p0,p1),line_segment(p1,p2),line_segment(p2,p3),line_segment(p3,p0)};

        bool flag=0;
        if (point_in_rec(st,p0,p2) && point_in_rec(ed,p0,p2)) flag=1;//if line_segment is in the rectangle
        else
        {
            for (int i=0;i<4;i++)
            {
                if (fast_exclusion_test(jerk_line,l[i]) && cross_test(jerk_line,l[i]))
                {
                    flag=1;
                    break;
                }
            }
        }
        puts(flag?"T":"F");
    }
    return 0;
}

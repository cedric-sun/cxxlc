#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-10;

struct point
{
    double x,y,z;
};

int n;
point p[30+5],tp;

inline double dist(const point &p1,const point &p2)
{
    return sqrt( pow( p1.x-p2.x , 2) + pow( p1.y-p2.y , 2) + pow( p1.z-p2.z , 2) );
}

int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++) scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
        tp.x=tp.y=tp.z=50;

        double ans;
        double radius=100;
        while (radius>1e-8)
        {
            int far_id;
            double far_dist=0;
            for (int i=0;i<n;i++)
            {
                double tmp=dist(tp,p[i]);
                if (tmp>far_dist)
                {
                    far_id=i;
                    far_dist=tmp;
                }
            }
            ans=far_dist;
            //try to move to the farthest point
            tp.x+=(p[far_id].x-tp.x)/far_dist*radius;
            tp.y+=(p[far_id].y-tp.y)/far_dist*radius;
            tp.z+=(p[far_id].z-tp.z)/far_dist*radius;

            radius*=0.98;
        }
        printf("%.5f\n",ans);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

const int pi=acos(-1.0);
const int eps=1e-8;

const int tpn=15;

struct point
{
    double x,y;
}p[100+5],tp[tpn+5];

int n;
double distsum[tpn+5];

inline double dist(const point &p1,const point &p2)
{return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) ); }

double calc_dist_sum(const point &sauerkraut)
{
    double ret=0;
    for (int i=0;i<n;i++) ret+=dist(p[i],sauerkraut);
    return ret;
}

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;++i)
            scanf("%lf %lf",&p[i].x,&p[i].y);

        for (int i=0;i<tpn;i++)
        {
            tp[i].x=1.0*rand()/RAND_MAX*10000;
            tp[i].y=1.0*rand()/RAND_MAX*10000;
            distsum[i]=calc_dist_sum(tp[i]);
        }

        double radius=5000;
        while (radius>1e-1)
        {
            for (int i=0;i<tpn;i++)
            {
                for (int j=0;j<30;j++)
                {
                    double random_angle=2*pi*rand()/RAND_MAX;
                    point tmp;
                    tmp.x=tp[i].x+radius*cos(random_angle);
                    tmp.y=tp[i].y+radius*sin(random_angle);

                    if ( tmp.x>-eps && tmp.x<eps+10000 && tmp.y>-eps && tmp.y<eps+10000)
                    {
                        double newdist=calc_dist_sum(tmp);
                        if (newdist<distsum[i])
                        {
                            distsum[i]=newdist;
                            tp[i]=tmp;
                        }
                    }
                }
            }

            radius*=0.75;
        }

        double mini=1e10;
        for (int i=0;i<tpn;i++)
            if (mini>distsum[i])
                mini=distsum[i];

        printf("%d\n",(int)(round(mini)+0.1));
    }
    return 0;
}

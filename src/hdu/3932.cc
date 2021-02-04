#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;

const int tpn=15;

struct point
{
    double x,y;
}p[1000+5],tp[tpn+5];

int n,m,pn;
double maxdist[tpn+5];

inline double dist(const point &p1,const point &p2)
{return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) ); }

double calc_max_dist(const point &sauerkraut)
{
    double ret=0;
    for (int i=0;i<pn;i++) ret=max(ret,dist(p[i],sauerkraut));
    return ret;
}

inline double deal(const double &a)
{
    return (round(a*10)+0.1)/10;
}

int main()
{
    while (~scanf("%d %d %d",&n,&m,&pn))
    {
        srand(time(NULL));
        for (int i=0;i<pn;++i)
            scanf("%lf %lf",&p[i].x,&p[i].y);

        for (int i=0;i<tpn;i++)
        {
            tp[i].x=1.0*rand()/RAND_MAX*n;
            tp[i].y=1.0*rand()/RAND_MAX*m;
            maxdist[i]=calc_max_dist(tp[i]);
        }

        double radius=max(n,m)*1.0/sqrt(1.0*pn);

        while (radius>1e-2)
        {
            for (int i=0;i<tpn;i++)
            {
                for (int j=0;j<20;j++)
                {
                    double random_angle=2*pi*rand()/RAND_MAX;
                    point tmp;
                    tmp.x=tp[i].x+radius*cos(random_angle);
                    tmp.y=tp[i].y+radius*sin(random_angle);

                    if ( tmp.x>-eps && tmp.x<eps+n && tmp.y>-eps && tmp.y<eps+m)
                    {
                        double newdist=calc_max_dist(tmp);
                        if (newdist<maxdist[i])
                        {
                            maxdist[i]=newdist;
                            tp[i]=tmp;
                        }
                    }
                }
            }
            radius*=0.75;
        }

        int id;
        double mini=1e10;
        for (int i=0;i<tpn;i++)
            if (maxdist[i]<mini)
            {
                id=i;
                mini=maxdist[i];
            }

        printf("(%.1f,%.1f).\n",deal(tp[id].x),deal(tp[id].y));
        printf("%.1f\n",deal(mini));
    }
    return 0;
}


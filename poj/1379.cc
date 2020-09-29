#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;

//parameters
const int       tpn=15;         //test point number
const double    step=0.75;      //annealing step
const double    min_T=1e-2;     //target


double n,m;     //n*m scale
int pn;         //pn traps

struct point
{
    double x,y;
}p[1000+5],test_p[tpn+5];

double mindist[tpn+5];

inline double dist(const point &p1,const point &p2)
{return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) ); }

double calcmindist(const point &sauerkraut)
{
    double ret=1e10;
    for (int i=0;i<pn;i++)
        ret=min(ret,dist(p[i],sauerkraut));
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        srand(T);
        scanf("%lf %lf %d",&n,&m,&pn);
        for (int i=0;i<pn;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        for (int i=0;i<tpn;i++)//setting test points set
        {
            test_p[i].x=rand()*1.0/(RAND_MAX) * n;
            test_p[i].y=rand()*1.0/(RAND_MAX) * m;
            mindist[i]=calcmindist(test_p[i]);
        }

        double radius=(m+n)/10;
        //this initializer is from poj disucuss.Or maybe min(n,m)/2 ?
        while (radius>min_T)//simulated annealing
        {
            for (int i=0;i<tpn;i++)//for every test point
            {
                for (int j=0;j<30;j++)//try 30 times
                {
                    double random_angle=2*pi*(1.0*rand()/RAND_MAX);
                    point tmp;
                    tmp.x=test_p[i].x+radius*cos(random_angle);
                    tmp.y=test_p[i].y+radius*sin(random_angle);//create a new random point
                    if ( tmp.x>-eps && tmp.x<eps+n && tmp.y>-eps && tmp.y<eps+m )//new test point is in the scale
                    {
                        double newdist=calcmindist(tmp);
                        if (newdist>mindist[i])//find a better point
                        {
                            test_p[i]=tmp;
                            mindist[i]=newdist;
                        }
                    }

                }
            }

            radius*=step;
        }

        int id;
        double maxi=0;
        for (int i=0;i<tpn;i++)
        {
            if (mindist[i]>maxi)
            {
                maxi=mindist[i];
                id=i;
            }
        }

        printf("The safest point is (%.1f, %.1f).\n",test_p[id].x,test_p[id].y);
    }
    return 0;
}

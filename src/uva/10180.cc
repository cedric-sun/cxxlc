#include <cstdio>
#include <cmath>

const double eps=1e-8;//minimun value constant

//return the sign
int sgn(double x) {return x<-eps?-1:x>eps;}

inline double sqr(double x) {return x*x;}

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	int input() {return scanf("%lf %lf",&x,&y);}
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
	double norm() {return sqrt(sqr(x)+sqr(y));}
};

//cross product a x b
double det(const point &a,const point &b)
{return a.x*b.y-a.y*b.x;}

//dot product
double dot(const point &a,const point &b)
{return a.x*b.x+a.y*b.y;}

//dist between two points
double dist(const point &a,const point &b)
{return (a-b).norm();}

double PointSegmentDist(const point &s,const point &t,const point &p)
{
    if (sgn(dot(p-s,t-s))<0) return (p-s).norm();
    if (sgn(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double r;
        point a,b,o(0,0);
        a.input();b.input();scanf("%lf",&r);
        double ans,ab;
        ans=ab=dist(a,b);
        if ( sgn(PointSegmentDist(a,b,o)-r)<0 )
        {
            double ao=dist(a,o),bo=dist(b,o);
            double ap1=sqrt(ao*ao-r*r),bp2=sqrt(bo*bo-r*r);
            double Ang1=acos( (ao*ao+bo*bo-ab*ab) / (2*ao*bo) );
            double Ang2=asin(ap1/ao),Ang3=asin(bp2/bo);
            ans=ap1+bp2+r*(Ang1-Ang2-Ang3);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

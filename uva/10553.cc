#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

const double pi=acos(-1.0);
const double K=pi/16;
const double eps=1e-8;//minimun value constant

const string str[]=
{
    "N","NbE","NNE","NEbN","NE","NEbE","ENE",
    "EbN","E","EbS","ESE","SEbE","SE","SEbS",
    "SSE","SbE","S","SbW","SSW","SWbS","SW",
    "SWbW","WSW","WbS","W","WbN","WNW","NWbW",
    "NW","NWbN","NNW","NbW"
};

map<string,int> StrToID;

int sgn(double x) {return x<-eps?-1:x>eps;}

inline double sqr(double x) {return x*x;}

struct point
{
    double x,y;
	point(double _x=0,double _y=0):x(_x),y(_y){}
	point operator + (const point &b) const
	{return point(x+b.x,y+b.y);}
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
	point operator * (const double b) const
	{return point(b*x,b*y);}
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

point point_rotate(const point &p,double A)
{
	double tx=p.x,ty=p.y;
	return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

double PointSegmentDist(const point &s,const point &t,const point &p)
{
    if (sgn(dot(p-s,t-s))<0) return (p-s).norm();
    if (sgn(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}


point path[1000+5];

int main()
{
    for (int i=0;i<32;i++) StrToID[str[i]]=i;
    int n;
    while (cin>>n,n)
    {
        string dir;double pace;point cur(0,0);
        for (int i=1;i<=n;i++)
        {
            cin>>dir>>pace;
            cur=cur+point(sin(K*StrToID[dir]) , cos(K*StrToID[dir]))*pace;
            path[i]=cur;
        }

        double angle;
        cin>>angle;
        point treasure=point_rotate(cur,-angle/180*pi);

        double ans=1e10;

        for (int i=0;i<n;i++)
            ans=min(ans,PointSegmentDist(path[i],path[i+1],treasure));
        printf("%.2f\n",ans);
    }
    return 0;
}

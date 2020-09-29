#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double eps=1e-8;//minimun value constant

//return the sign of a double type
int sgn(double x)
{
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;
	return -1;
}

struct point
{
    double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	int input() {return scanf("%lf %lf",&x,&y);}
	point operator + (const point &b) const
	{return point(x+b.x,y+b.y);}
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
	bool operator == (const point &b) const
	{return sgn(x-b.x)==0 && sgn(y-b.y)==0;}
	point operator * (const double b) const
	{return point(b*x,b*y);}
	point operator / (const double b) const
	{return point(x/b,y/b);}
};

double det(const point &a,const point &b)
{return a.x*b.y-a.y*b.x;}

inline int crossOp(const point &p1,const point &p2,const point &p3)
{return sgn(det(p2-p1,p3-p1));}

bool CH_CMP(const point &a,const point &b)
{return sgn(a.x-b.x)<0 || (sgn(a.x-b.x)==0 && sgn(a.y-b.y)<0);}

vector<point> Convex_Hull(vector<point> &pset)
{
    vector<point> CH;
	int n = pset.size();
	if (n <= 1) {return pset;}
	sort(pset.begin(), pset.end(),CH_CMP);
	for (int i = 0; i < n; CH.push_back(pset[i++]))
	{
		while (CH.size() > 1 && crossOp(CH[CH.size()-2],CH.back(),pset[i]) <= 0)
			CH.pop_back();
	}
	for (int i = n - 2, t = CH.size(); i >= 0; CH.push_back(pset[i--]))
	{
		while (CH.size() > t && crossOp(CH[CH.size()-2],CH.back(),pset[i]) <= 0)
			CH.pop_back();
	}
	CH.pop_back();
	return CH;
}

//1:point is in polygon
//0:point is out of polygon
//-1:point is on the boundary of polygon
//normally you can use if (contain_OlogN()) to judge this
int contain_OlogN(const vector<point> &ref,const point &p)
{
	int n=ref.size();
	point tmp=(ref[0]+ref[n/3]+ref[2*n/3])/3.0;
	int l=0,r=n;
	while (r-l>1)
	{
		int mid=(l+r)>>1;
		if (sgn(det(ref[l]-tmp,ref[mid]-tmp))>0)
		{
			if ( sgn(det(ref[l]-tmp,p-tmp))>=0 && sgn(det(ref[mid]-tmp,p-tmp))<0) r=mid;
			else l=mid;
		}
		else
		{
			if ( sgn(det(ref[l]-tmp,p-tmp))<0 && sgn(det(ref[mid]-tmp,p-tmp))>=0) l=mid;
			else r=mid;
		}
	}
	r%=n;
	int z=sgn(det(ref[r]-p,ref[l]-p))-1;
	if (z==-1) return 1;
	return z;
}

double polygon_Area(const vector<point> &ref)
{
	double sum=0;
	int n=ref.size();
	for (int i=0;i<n;i++) sum+=det(ref[i],ref[(i+1)%n]);
	return sum/2;
}

struct _kingdom
{
    bool vis;
    vector<point> contour;
    double size;
}kingdom[25];

int main()
{
    int siteN,kingdomN=0;
    while (scanf("%d",&siteN),~siteN)
    {
        vector<point> tmp;
        for (int i=0;i<siteN;i++)
        {
            point p;
            p.input();
            tmp.push_back(p);
        }
        _kingdom &ref=kingdom[kingdomN++];
        ref.contour=Convex_Hull(tmp);
        ref.size=polygon_Area(ref.contour);
        ref.vis=0;
    }

    double ans=0;
    point m;
    while (~m.input())
    {
        for (int i=0;i<kingdomN;i++)
        if (!kingdom[i].vis && contain_OlogN(kingdom[i].contour,m))
        {
            ans+=kingdom[i].size;
            kingdom[i].vis=1;
        }
    }
    printf("%.2f\n",ans);
    return 0;
}

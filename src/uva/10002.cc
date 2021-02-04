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

double polygon_Area(const vector<point> &ref)
{
	double sum=0;
	int n=ref.size();
	for (int i=0;i<n;i++) sum+=det(ref[i],ref[(i+1)%n]);
	return sum/2;
}

point polygon_MassCenter(const vector<point> &ref)
{
	double areaS=polygon_Area(ref);
	//you need to assure areaS is positive depended on the order of points in ref
	point ans=point(0,0);
	if (sgn(areaS)==0) return ans;
	int n=ref.size();
	for (int i=0;i<n;i++) ans=ans+(ref[i]+ref[(i+1)%n])*det(ref[i],ref[(i+1)%n]);
	return ans/areaS/6;
}

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

int main()
{
    int n;
    while (scanf("%d",&n),n>=3)
    {
        vector<point> pset;
        for (int i=0;i<n;i++)
        {
            point tmp;
            tmp.input();
            pset.push_back(tmp);
        }
        point ans=polygon_MassCenter(Convex_Hull(pset));
        printf("%.3f %.3f\n",ans.x,ans.y);
    }
    return 0;
}

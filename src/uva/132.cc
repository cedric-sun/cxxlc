#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int sgn(int x) {return x<0?-1:x>0;}

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	int input() {return scanf("%d %d",&x,&y);}
	point operator + (const point &b) const
	{return point(x+b.x,y+b.y);}
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
	bool operator == (const point &b) const
	{return sgn(x-b.x)==0 && sgn(y-b.y)==0;}
	point operator * (const int b) const
	{return point(b*x,b*y);}
	point operator / (const int b) const
	{return point(x/b,y/b);}
};

//cross product a x b
int det(const point &a,const point &b)
{return a.x*b.y-a.y*b.x;}

//dot product a . b
int dot(const point &a,const point &b)
{return a.x*b.x+a.y*b.y;}

//sgn of cross product: vector(p1p2) x vector (p1p3)
inline int crossOp(const point &p1,const point &p2,const point &p3)
{return sgn(det(p2-p1,p3-p1));}

//comparison function needed when sorting the points in Graham-Scan-MK2
bool CH_CMP(const point &a,const point &b)
{return sgn(a.x-b.x)<0 || (sgn(a.x-b.x)==0 && sgn(a.y-b.y)<0);}

//ignore co-linear points
vector<point> Convex_Hull(vector<point> pset)
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

//whether p is over segment(s-t) when it is rotated to horizon
bool PointOverSegment(const point &s,const point &t,const point &p)
{
    point n(t.y-s.y,s.x-t.x);//normal vector of (x,y) is (y,-x)
    return sgn(det(n,p-s)) * sgn(det(n,p-t)) <0 ;
}

//whether p is on segment(s-t)
bool PointOnSegment(const point &s,const point &t,const point &p)
{return sgn(det(p-s,t-s))==0 && sgn(dot(p-s,p-t))<=0;}

int main()
{
    char objname[25];
    while (scanf("%s",objname),objname[0]!='#')
    {
        point MC;
        MC.input();
        vector<point> contour;
        int x,y;
        while (scanf("%d %d",&x,&y),x||y)
            contour.push_back(point(x,y));
        vector<point> convex=Convex_Hull(contour);
        int len1=contour.size(),len2=convex.size();
        int ans=0x7FFFFFFF;
        for (int i=0;i<len2;i++)
        {
            //if masscenter is not over the current segment, no need for further calculation
            point &s=convex[i],&t=convex[(i+1)%len2];
            if (!PointOverSegment(s,t,MC)) continue;
            int maxID=-1;
            for (int j=0;j<len1;j++)
            {
                if (PointOnSegment(s,t,contour[j]))
                    maxID=max(maxID,j);
            }
            ans=min(ans,maxID);
        }
        printf("%-20s%d\n",objname,ans+1);
    }
    return 0;
}

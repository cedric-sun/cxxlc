#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int sgn(int x)
{return x<0?-1:x>0;}

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	int input() {return scanf("%d %d",&x,&y);}
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
};

//cross product a x b
int det(const point &a,const point &b)
{return a.x*b.y-a.y*b.x;}

//sgn of cross product: vector(p1p2) x vector (p1p3)
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

int main()
{
    int T;
    scanf("%d",&T);
    printf("%d\n",T);
    for (int K=0;K<T;K++)
    {
        int n;
        if (K)
        {
            puts("-1");
            scanf("%d",&n);//read the -1
        }
        vector<point> contour;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            point p;
            p.input();
            if (i!=n-1) contour.push_back(p);
        }
        vector<point> convex=Convex_Hull(contour);
        int len=convex.size();
        printf("%d\n",len+1);
        int ID=0;
        for (int i=0;i<len;i++)
            if (convex[i].y<convex[ID].y || (convex[i].y==convex[ID].y && convex[i].x<convex[ID].x))
                ID=i;
        for (int i=0;i<len;i++)
            printf("%d %d\n",convex[(ID+i)%len].x,convex[(ID+i)%len].y);
        printf("%d %d\n",convex[ID].x,convex[ID].y);
    }
    return 0;
}

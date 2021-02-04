#include <cstdio>
#include <cmath>
#include <vector>
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
	point operator - (const point &b) const
	{return point(x-b.x,y-b.y);}
};

inline double det(const point &a,const point &b)
{return a.x*b.y-a.y*b.x;}

bool is_convex(vector<point> &ref)
{
    int SIGN=sgn(det(ref[1]-ref[0],ref[2]-ref[1]));
    int n=ref.size();
    for (int i=1;i<n;i++)
        if (sgn(det(ref[(i+1)%n]-ref[i],ref[(i+2)%n]-ref[(i+1)%n]))!=SIGN)
            return 0;
    return 1;
}

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        vector<point> tmp;
        for (int i=0;i<n;i++)
        {
            point p;
            p.input();
            tmp.push_back(p);
        }
        puts(is_convex(tmp)?"No":"Yes");
    }
    return 0;
}

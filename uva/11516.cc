#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005];
int n,m;
bool judge(double k)
{
	int cnt=1;
	double coverto=a[0]+k;
	for (int i = 0; i < m; i++)
		if (a[i]>coverto)
		{
			coverto=a[i]+k;
			cnt++;
		}
		return cnt<=n;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i = 0; i < m; i++)
			scanf("%d",a+i);

		sort(a,a+m);

		double lo=0,hi=1000000,mid;
		while (hi-lo>0.05)
		{
			mid=(lo+hi)/2;
			if (judge(mid*2)) hi=mid;
			else lo=mid;
		}

		printf("%.1f\n",mid);
	}
	return 0;
}

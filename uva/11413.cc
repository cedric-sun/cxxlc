#include <cstdio>
#include <algorithm>
using std::max;

int n,m,a[1005];

bool judge(double k)
{
	int cnt=1,sum=0;
	for (int i = 0; i < n; i++)
	{
		if (sum+a[i]>k)
		{
			sum=0;
			cnt++;
		}
		sum+=a[i];
	}
	return cnt<=m;
}

int main()
{
	while (~scanf("%d %d",&n,&m))
	{
		int sum=0,maxv=0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",a+i);
			sum+=a[i];
			maxv=max(maxv,a[i]);
		}

		double lo=maxv,hi=sum,mid=1;

		while (hi-lo>0.2)
		{
			mid=(hi+lo)/2;
			if (judge(mid)) hi=mid;
			else lo=mid;
		}

		printf("%d\n",(int)(mid+0.5));
	}
	return 0;
}

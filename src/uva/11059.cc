#include <cstdio>
int main()
{
	int n,cnt=1;
	long long a,ans,q[18];
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&q[i]);
		}
		ans=0;
		for (int start = 0; start < n; ++start)
		{
			for (int end = start; end < n; ++end)
			{
				a=1;
				for (int p=start;p<=end;p++)
					a*=q[p];
				if (a>ans)
					ans=a;
			}

		}
		printf("Case #%d: The maximum product is %lld.\n\n",cnt++,ans);
	}
	return 0;
}


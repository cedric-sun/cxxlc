#include <cstdio>
#include <cmath>
int main()
{
	int T;
	long long n,s[2],v[2],ans;
	bool s0f,s1f;
	scanf("%d",&T);
	for (int cnt = 1; cnt <=T; cnt++)
	{
		scanf("%lld %lld %lld %lld %lld",&n,s,v,s+1,v+1);
		ans=0;
		s0f=s1f=0;
		if (s[0]<sqrt(n)) s0f=1;
		if (s[1]<sqrt(n)) s1f=1;

		if (s0f&&s1f)
		{
			int flag=(s[1]*v[0]>s[0]*v[1]);
			for (int i = 0; i <=s[!flag]-1; i++)
			{
				long long temp=(	((n-i*s[flag])/s[!flag])*v[!flag]	)+i*v[flag];
				if (temp>ans)
					ans=temp;
			}
		}
		else
		{
			int flag=(s[0]>s[1]);
			for (int i = 0; i <=n/s[!flag]; i++)
			{
				long long temp=(	((n-i*s[!flag])/s[flag])*v[flag]	)+i*v[!flag];
				if (temp>ans)
					ans=temp;
			}
		}
		printf("Case #%d: %lld\n",cnt,ans);
	}
	return 0;
}

#include <cstdio>
int a[1005];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",a+i);
			sum+=a[i];
		}
		double aver=1.0*sum/n;
		int cnt=0;
		for (int i = 0; i < n; i++)
			if (a[i]>aver) cnt++;
		printf("%.3f%%\n",100.0*cnt/n);
	}
	return 0;
}

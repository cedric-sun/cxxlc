#include <cstdio>
int main()
{
	int k,cnt;
	int ansx[10086],ansy[10086];
	while (~scanf("%d",&k))
	{
	    cnt=0;
		for (int y=k+1;y<=2*k;y++)
			if ((k*y)%(y-k)==0)
                    ansx[cnt]=(k*y)/(y-k),ansy[cnt++]=y;
        printf("%d\n",cnt);
        for (int i=0;i<cnt;i++)
		printf("1/%d = 1/%d + 1/%d\n",k,ansx[i],ansy[i]);
	}
	return 0;
}


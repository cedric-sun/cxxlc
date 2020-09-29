#include <cstdio>
#include <cstring>
int main()
{
    int w,d,fnt[10],side[10],sum,temp;
    bool used[10];
    while (~scanf("%d %d",&w,&d))
    {
        if (!w) break;
        sum=0;
        for (int i=0; i<w; i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            *(fnt+i)=temp;
        }
        for (int i=0; i<d; i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            *(side+i)=temp;
        }

        memset(used,0,sizeof used);

        for (int i=0; i<d; i++)
        {
            for (int j=0; j<w; j++)
            {
                if (!used[j])
                {
                    if (side[i]==fnt[j])
                    {
                        sum-=side[i];
                        used[j]=true;
                        break;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

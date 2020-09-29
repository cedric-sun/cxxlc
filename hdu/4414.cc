#include <stdio.h>
#include <string.h>

char map[55][55];

int main()
{
    int n,i,j,k,ans,flag;
    while(~scanf("%d",&n),n)
    {
        ans = 0;
        for(i = 0; i<n; i++)
            scanf("%s",map[i]);
        int cnt1,cnt2,cnt3,cnt4;
        for(i=1; i<n-1; i++)
        {
            for(j=1; j<n-1; j++)
            {
                flag=1;
                if(map[i][j]=='#')//这个#是中间的
                {
                    cnt1=cnt2=cnt3=cnt4=0;
                    for(k=i-1; k>=0; k--)//向上找
                    {
                        if(map[k][j]=='#')
                        {
                            if(map[k][j-1]=='#'||map[k][j+1]=='#')//每找一个看这个的上下是否有#，有则不是要求的十字架
                            {
                                flag=0;
                                break;
                            }
                            cnt1++;//统计向上伸长的长度
                        }
                        else break;
                    }
                    if(cnt1<1) flag=0;//由于十字架长度要最少为3,所以小于1肯定不行
                    for(k=i+1; k<n&&flag; k++)//下向
                    {
                        if(map[k][j]=='#')
                        {
                            if(map[k][j-1]=='#'||map[k][j+1]=='#')
                            {
                                flag=0;
                                break;
                            }
                            cnt2++;
                        }
                        else break;
                    }
                    if(cnt1!=cnt2) flag=0;//上下不等，肯定不是十字架
                    for(k=j-1; k>=0&&flag; k--)//左向
                    {
                        if(map[i][k]=='#')
                        {
                            if(map[i-1][k]=='#'||map[i+1][k]=='#')
                            {
                                flag=0;
                                break;
                            }
                            cnt3++;
                        }
                        else break;
                    }
                    if(cnt3<1) flag=0;
                    for(k=j+1; k<n&&flag; k++)//右向
                    {
                        if(map[i][k]=='#')
                        {
                            if(map[i-1][k]=='#'||map[i+1][k]=='#')
                            {
                                flag=0;
                                break;
                            }
                            cnt4++;
                        }
                        else break;
                    }
                    if(cnt3!=cnt4) flag=0;
                    if(flag) ans++;//所有条件符合，个数加1
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

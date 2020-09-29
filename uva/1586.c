#include <stdio.h>
#include <ctype.h>
double mass['O'+1];
int main()
{
    int cases,power,iip;
    double ans;
    char now,latest_element;
    mass['C']=12.01,mass['H']=1.008,mass['O']=16.00,mass['N']=14.01;
    scanf("%d",&cases);
    getchar();
    while (cases--)
    {
        ans=latest_element=0,power=iip=1;
        while ((now=getchar())!=EOF)
        {

            if (isalpha(now))
            {
                 if (!latest_element)
                    latest_element=now;
                else
                {
                ans+=mass[latest_element]*power;
                latest_element=now;
                power=iip=1;
                }
            }
            else if (isalnum(now))
            {
                if (iip)
                {
                    power=now-'0';
                    iip=0;
                }
                else
                    power=power*10+now-'0';
            }
            else if (now=='\n')
            {
                ans+=mass[latest_element]*power;
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
char s1[100010],s2[100010];
int main()
{
    int i,j,l1,l2,point,error;
    while (scanf("%s %s",s1,s2)!=EOF)
    {
        l1=strlen(s1),l2=strlen(s2),point=error=0;
        for (i=0; i<l1; i++)
        {
            for (j=point; j<l2; j++)
            {
                if (s1[i]==s2[j])
                {
                    point=j+1;
                    break;
                }
            }
            if (j==l2)
            {
                error=1;
                break;
            }
        }
        printf(error?"NO\n":"YES\n");
    }
    return 0;
}

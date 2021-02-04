#include <stdio.h>
#include <string.h>
char DNA[50][1000],ans[1000];
int frequence[1000][4];
int main()
{
    int i,j,m,n,cases,maxfrequence,maxchar,sum;
    char temp;
    scanf("%d",&cases);
    while (cases--)
    {
        memset(frequence,0,sizeof(frequence));
        scanf("%d %d",&m,&n);
        getchar();
        for (i=0; i<m; i++,getchar())
            for (j=0; j<n; j++)
            {
                temp=getchar();
                DNA[i][j]=temp;
                switch(temp)
                {
                case 'A':
                    frequence[j][0]++;
                    break;
                case 'C':
                    frequence[j][1]++;
                    break;
                case 'G':
                    frequence[j][2]++;
                    break;
                case 'T':
                    frequence[j][3]++;
                    break;
                }
            }



        for (i=0; i<n; i++)
        {
            maxfrequence=maxchar=0;
            for (j=0; j<4; j++)
                if (frequence[i][j]>maxfrequence)
                {
                    maxchar=j;
                    maxfrequence=frequence[i][j];
                }
            switch(maxchar)
            {
            case 0:
                ans[i]='A';
                break;
            case 1:
                ans[i]='C';
                break;
            case 2:
                ans[i]='G';
                break;
            case 3:
                ans[i]='T';
                break;
            }
        }

        sum=0;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                if (DNA[j][i]!=ans[i])
                    sum++;
        for (i=0; i<n; i++)
            putchar(ans[i]);
        putchar('\n');
        printf("%d\n",sum);
    }
    return 0;
}

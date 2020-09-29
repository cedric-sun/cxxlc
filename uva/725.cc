#include <cstdio>
#include <cstring>
bool used[10],check[10];
bool legal(int a)
{
    memcpy(check,used,10);
    for (int i = 0; i < 5; ++i)
    {
        int temp=a%10;
        if (check[temp]) return false;
        check[temp]=true;
        a/=10;
    }
    return true;

}
int main()
{
    int n,ub,ia,ib,ic,id,ie,temp;
    bool flag,flag2=0;
    while (scanf("%d",&n)&&n)
    {
        if (flag2)
            putchar('\n');
        else
            flag2=1;
        flag=0;
        ub=98765/n+1;
        int u[5];
        for (int i = 0; i < 5; ++i)
        {
            u[i]=ub%10;
            ub/=10;
        }

        for (ia = 0; ia <=u[4]; ++ia)
        {
            used[ia]=true;
            for (ib = (!ia)?1:0; ib <= (ia==u[4]?u[3]:9); ++ib)
            {
                if (used[ib]) continue;
                used[ib]=true;
                for (ic = (!ia&&ib==1)?2:0; ic <=((ia==u[4]&&ib==u[3])?u[2]:9); ++ic)
                {
                    if (used[ic]) continue;
                    used[ic]=true;
                    for (id = (!ia&&ib==1&&ic==2)?3:0; id <= ((ia==u[4]&&ib==u[3]&&ic==u[2])?u[1]:9); ++id)
                    {
                        if (used[id]) continue;
                        used[id]=true;
                        for (ie = (!ia&&ib==1&&ic==2&&id==3)?4:0; ie <= ((ia==u[4]&&ib==u[3]&&ic==u[2]&&id==u[1])?u[0]:9); ++ie)
                        {
                            if (used[ie]) continue;
                            used[ie]=true;
                            temp=10000*ia+1000*ib+100*ic+10*id+ie;
                            if (legal(temp*n))
                            {
                                printf("%d / %05d = %d\n",temp*n,temp,n);
                                flag=1;
                            }
                            used[ie]=false;

                        }
                        used[id]=false;
                    }
                    used[ic]=false;
                }
                used[ib]=false;
            }
            used[ia]=false;
        }
        if (!flag)
            printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

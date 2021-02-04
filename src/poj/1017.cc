#include <cstdio>
#include <algorithm>
int main()
{
    int s1,s2,s3,s4,s5,s6,ans;
    while (~scanf("%d %d %d %d %d %d",&s1,&s2,&s3,&s4,&s5,&s6))
    {
        ans=0;
        ans+=s6;
        ans+=s5;
        s1=max(0,s1-s5*11);
        ans+=s4;
        if (s2>=s4*5)
            s2-=s4*5
    }
}

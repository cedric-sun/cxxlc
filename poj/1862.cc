#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n,greater<int>());
    double cur=a[0];
    for (int i=1;i<n;i++)
        cur=2*sqrt(a[i]*cur*1.0);
    printf("%.3f\n",cur);
    return 0;
}

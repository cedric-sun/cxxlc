#include <stdio.h>
int ifvowel(char a)
{
    if (a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u'&&a!='A'&&a!='E'&&a!='I'&&a!='O'&&a!='U')
        return 0;
    return 1;
}
int ifalphabet(char a)
{
    if (a>='a'&&a<='z'||a>='A'&&a<='Z')
        return 1;
    return 0;
}
int main()
{
    int ifprint,ifprintstrbegin;
    char a,prev,strbegin;
    prev=' ';
    while (a=getchar(),a!=EOF)
    {
        ifprint=1;
        if (ifalphabet(a)&&(!ifalphabet(prev)))
        {


            strbegin=a;
            if (ifvowel(strbegin))
            {
               ifprint=1;
                ifprintstrbegin=0;
            }
            else
            {

                 ifprint=0;
                ifprintstrbegin=1;
            }
        }
        if (ifalphabet(prev)&&(!ifalphabet(a)))
        {

            if (ifprintstrbegin)
                printf("%cay",strbegin);
            else
                printf("ay");
        }
            if (ifprint)
                printf("%c",a);
        prev=a;

    }
    return 0;
}

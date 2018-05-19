#include <stdio.h>
int main ()
{
int i, n,a;
int count=0;
scanf ("%d", &n);
for (i=0; i<n; i++)
{
scanf ("%d", &a);
if (a>0)
count=count+1;
}
printf("%d\n",count);
return 0;
}

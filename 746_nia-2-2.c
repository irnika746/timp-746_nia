#include <stdio.h>
#include <math.h>
int main ()
{
int i, n, a, sum1, sum2;
sum1=0;
sum2=0;
scanf ("%d", &n);
for (i=0; i<n; i++)
{
scanf ("%d", &a);
if ((i%2)==0)
sum1=sum1+a*a;
else sum2=sum2+(-1)*a*a;
}
int sum=(-1)*(sum1+sum2);
printf ("%d\n", sum);
return 0;
}

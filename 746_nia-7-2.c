#include <stdio.h>
#include <stdlib.h>

void sortirovka_shell(int arr[], int N)
{
int i, j, k, t ;
for (k=N/2;k>0; k=k/2)
{
for (i=k; i<N; i++)
{
for(j=i-k; j>=0; j=j-k)
{
if (arr[j+k] >= arr[j])
break;
else
{
t=arr[j];
arr[j]=arr[j+k];
arr[j+k]=t;
}
}
}
}
}

int main ()
{
int n, i;
int *c;
scanf("%d", &n);
c=(int *)calloc(n, sizeof(int));
for (i=0; i<n; i++)
{
scanf("%d", &c[i]);
}
sortirovka_shell(c, n);
for(i=0; i<n; i++)
{
printf("%d ", (c[i]));
}
printf("\n");
return 0;
}

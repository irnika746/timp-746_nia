#include <stdio.h>
#include <stdlib.h>

void hoal_sort (int *N, int left, int right)
{
int pivot;
int l = left; //левая граница
int r = right; // правая граница
pivot=N[left];
while (left < right) // пока границы не сомкнутся
{
while ((N[right] >= pivot) && (left < right))
right--;
if (left != right)
{
N[left] = N[right];
left++;// сдвиг вправо
}
while ((N[left] <= pivot) && (left < right))
left++;
if (left != right) // если границы не сошлись
{
N[right] =N[left];
right--; // сдвиг вправо
}
}
N[left] = pivot;//  меняем разрешающий элемент
pivot = left;
left = l;
right = r;

if (left < pivot) 
hoal_sort(N, left, pivot - 1);
if (right > pivot)
hoal_sort(N, pivot + 1, right);
}

int main()
{
int *arr;
int i, n;
scanf("%d", &n);
arr =  (int *)calloc(n, sizeof(int));
for (i = 0;i< n;i++)
{
scanf("%d", &arr[i]);
}
hoal_sort(arr,0,n); 
for(int i = 0; i<n; i++)
printf("%d ", arr[i]);
printf("\n");
return 0;
}

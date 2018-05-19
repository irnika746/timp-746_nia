#include <stdio.h>
#include <stdlib.h>

void proseivanie(int *N, int ptr, int b)
{
int max_potomoc; // индекс максимального потомка
int done = 0;// флаг, куча сформирована
while ((ptr * 2 <= b) && (!done))// поиск  последнего ряда
{
if (ptr * 2 == b)
max_potomoc = ptr * 2;//запомнили левого
else if (N[ptr * 2] > N[ptr * 2 + 1])
max_potomoc = ptr * 2;
else
max_potomoc = ptr * 2 + 1;

if (N[ptr] < N[max_potomoc])// сравнение вершины и потомка
{
int k = N[ptr]; // меняем их местами
N[ptr] = N[max_potomoc];
N[max_potomoc] = k;
ptr = max_potomoc;
}
else
done = 1; // пирамида получена
}
}

void sortirovka_pir(int *number, int arr)
{
for (int i = (arr / 2) - 1; i >= 0; i--)//делаем нижний ряд пирамиды
proseivanie(number, i, arr);

for (int i = arr - 1; i >= 1; i--)// остальные элементы на просевку
{
int k = number[0];
number[0] = number[i];
number[i] = k;
proseivanie(number, 0, i - 1);
}
}


int main ()
{
int n, i;
int *arr;
scanf("%d", &n);
arr  =  (int *)calloc(n, sizeof(int));
for (i = 0;i< n;i++)
{
scanf("%d", &arr[i]);
}
sortirovka_pir(arr, n);
for(i = 0; i < n;i++)
{
printf("%d ", (arr[i]));
}
printf ("\n");
return 0;
}


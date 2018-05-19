#include <stdio.h>
#include <stdlib.h>
typedef struct list {
int value;
struct list *next;
struct list *prev;
}list;
list *head=NULL;
list *tail=NULL;


int init(int date )
{
list *tmp=(list*)malloc(sizeof(list));
tmp->value=date;
tmp->next=NULL;
tmp->prev=NULL;
head=tmp;
tail=tmp;
}

int isEmpty()
{
if ((head==NULL)&&(tail==NULL))
return 1;
else return 0; 
}

void insertEnd (int date)//заполнение
{
if (isEmpty()==1)
init (date);
else
{
list *tmp=(list*) malloc(sizeof(list));
tmp->value=date;
tmp->next=NULL;
tmp->prev=tail;
tail=tmp;
tmp->prev->next=tmp;
/*if (tail==NULL) 
head=tmp;
if (tmp==NULL)
exit(EXIT_SUCCESS);*/
}
}

void insertList()//вывод
{
list *tmp=head;
printf("%d ", tmp->value);
while (tmp->next!=NULL)
{
tmp=tmp->next;
printf("%d ", tmp->value);
}
printf("\n");
}

list *findK(int p)// поиск к-го элемента
{
list *tmp=head;
for (int i=1; i<p; i++)
{
tmp=tmp->next;
if(tmp==NULL)
break;
}
return tmp;
}

void delitK(list *tmp)//удаление r-го
{
int flag=0;
if (tmp==NULL)
flag=1;

if (tmp==head && flag==0)
{
head=tmp->next;
tmp->next->prev=NULL;
free(tmp);
flag=1;
}

if (tmp!=head && flag==0)
{
tmp->prev->next=tmp->next;
tmp->next->prev=tmp->prev;
free(tmp);
flag=1;
}}


list *findDate (int p)// поиск значения
{
list *tmp=head;
while(tmp->value!=p && tmp!=NULL)
{
tmp=tmp->next;
}
return tmp;
}

/*void delitDate(int p)
{
if (isEmpty()==0)
{
list *tmp=head;
while (tmp->value!=p)
	tmp=tmp->next;
tmp->next->prev=tmp->prev;
tmp->prev->next=tmp->next;
free(tmp);
}
}*/

int insertAfter (int  n, int v)// вставка после n, элемент v
{
int data=1;
list *tmp1=head;
list *tmp=(list*)malloc(sizeof( list));
while (data!=n)
{
tmp1=tmp1->next;
data++;
}
tmp->value=v;
tmp->next=tmp1->next;
tmp->prev=tmp1;
tmp->next->prev=tmp;
tmp->prev->next=tmp;

}

int insertBefore (int n, int v)
{
int data=1;
list *tmp=head;
list *tmp1=(list*) malloc(sizeof(list));
while (data!=n)
{ 
tmp=tmp->next;
data++;
}
tmp1->value=v;
tmp1->next=tmp;
tmp1->prev=tmp->prev;
tmp->prev->next= tmp1;
tmp->prev=tmp1;

}

void delit()//удаление списка
{
if (isEmpty()==0)
{
list *tmp=head;
list *tmp1=NULL;
do
{
tmp1=tmp->next;
free(tmp);
tmp=tmp1;}
while(tmp!=NULL);
head=NULL;
tail=NULL;}
}

int main ()
{
int i, n, nom;
scanf("%d", &n);
scanf ("%d",&nom);
if (isEmpty()==1)
{init (nom);
for (i=1; i<n; i++)
{
scanf ("%d", &nom);
insertEnd(nom);
}
insertList();
}

scanf ("%d", &nom);
delitK(findK(nom));
insertList();

scanf ("%d", &nom);
delitK(findDate(nom));
insertList();

scanf("%d",&n);
scanf("%d",&nom);
insertAfter(n, nom);
insertList();

scanf("%d",&n);
scanf("%d", &nom);
insertBefore(n, nom);
insertList();

delit();

return 0;
}

